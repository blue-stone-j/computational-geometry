#ifndef CONVEX_HULL_2D
#define CONVEX_HULL_2D

#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>

#include "Eigen/Dense"

/* from Apollo 6.0 */

template <typename T>
struct Point2D
{
  T x = 0;
  T y = 0;
};

template <class PointT>
class PointCloud
{
 public:
  double timestamp_ = 0.0;
  std::vector<PointT> points;
  std::vector<float> points_height;
  size_t size() const { return points.size(); }
  bool empty() { return points.empty(); }
  void push_back(PointT pt, float height = std::numeric_limits<float>::max());
  void clear();
  void resize(size_t size);
  void reserve(size_t size);

  PointT &at(size_t pos);
  const PointT &at(size_t pos) const;
  PointT &operator[](size_t pos);
  const PointT &operator[](size_t pos) const;
};

template <class CLOUD_IN_TYPE, class CLOUD_OUT_TYPE>
class ConvexHull2D
{
 public:
  ConvexHull2D() :
    in_cloud_(nullptr)
  {
    points_.reserve(1000.0);
    polygon_indices_.reserve(1000.0);
  }
  ~ConvexHull2D() { in_cloud_ = nullptr; }

  // main interface to get polygon from input point cloud
  bool GetConvexHull(const CLOUD_IN_TYPE &in_cloud, CLOUD_OUT_TYPE *out_polygon)
  {
    SetPoints(in_cloud);
    if (!GetConvexHullMonotoneChain(out_polygon))
    {
      return MockConvexHull(out_polygon);
    }
    return true;
  }

  // main interface to get polygon from input point cloud(without ground points)
  bool GetConvexHullWithoutGround(const CLOUD_IN_TYPE &in_cloud,
                                  const float &distance_above_ground_threshold,
                                  CLOUD_OUT_TYPE *out_polygon)
  {
    CLOUD_IN_TYPE in_cloud_without_ground;
    in_cloud_without_ground.reserve(in_cloud.size());
    for (std::size_t id = 0; id < in_cloud.size(); ++id)
    {
      // compute point_heigh, note std::numeric_limits<float>::max() is the default value
      if (in_cloud.points_height[id] >= distance_above_ground_threshold)
      {
        in_cloud_without_ground.push_back(in_cloud[id]);
      }
    }
    if (in_cloud_without_ground.empty())
    {
      return GetConvexHull(in_cloud, out_polygon);
    }
    else
    {
      SetPoints(in_cloud_without_ground);
      if (!GetConvexHullMonotoneChain(out_polygon))
      {
        return MockConvexHull(out_polygon);
      }
    }
    return true;
  }
  // main interface to get polygon from input point cloud
  // (without ground points and points above the head of self-driving car)
  bool GetConvexHullWithoutGroundAndHead(const CLOUD_IN_TYPE &in_cloud, const float &distance_above_ground_threshold,
                                         const float &distance_beneath_head_threshold, CLOUD_OUT_TYPE *out_polygon)
  {
    CLOUD_IN_TYPE in_cloud_without_ground_and_head;
    in_cloud_without_ground_and_head.reserve(in_cloud.size());
    for (std::size_t id = 0; id < in_cloud.size(); ++id)
    {
      // compute point_heigh, note std::numeric_limits<float>::max() is the
      // default value
      if (in_cloud.points_height[id] == std::numeric_limits<float>::max()
          || (in_cloud.points_height[id] >= distance_above_ground_threshold
              && in_cloud.points_height[id] <= distance_beneath_head_threshold))
      {
        in_cloud_without_ground_and_head.push_back(in_cloud[id]);
      }
    }
    if (in_cloud_without_ground_and_head.empty())
    {
      return GetConvexHull(in_cloud, out_polygon);
    }
    else
    {
      SetPoints(in_cloud_without_ground_and_head);
      if (!GetConvexHullMonotoneChain(out_polygon))
      {
        return MockConvexHull(out_polygon);
      }
    }
    return true;
  }

 private:
  // save points in local memory, and transform to double
  void SetPoints(const CLOUD_IN_TYPE &in_cloud);

  // mock a polygon for some degenerate cases
  bool MockConvexHull(CLOUD_OUT_TYPE *out_polygon);

  // compute convex hull using Andrew's monotone chain algorithm
  bool GetConvexHullMonotoneChain(CLOUD_OUT_TYPE *out_polygon);

  // given 3 ordered points, return true if in counter clock wise.
  bool IsCounterClockWise(const Eigen::Vector2d &p1, const Eigen::Vector2d &p2,
                          const Eigen::Vector2d &p3, const double &eps)
  {
    Eigen::Vector2d p12 = p2 - p1;
    Eigen::Vector2d p13 = p3 - p1;
    return (p12(0) * p13(1) - p12(1) * p13(0) > eps);
  }

 private:
  std::vector<Eigen::Vector2d> points_;
  std::vector<std::size_t> polygon_indices_;
  const CLOUD_IN_TYPE *in_cloud_;
};

template <class CLOUD_IN_TYPE, class CLOUD_OUT_TYPE>
void ConvexHull2D<CLOUD_IN_TYPE, CLOUD_OUT_TYPE>::SetPoints(const CLOUD_IN_TYPE &in_cloud)
{
  points_.resize(in_cloud.size());
  for (std::size_t i = 0; i < points_.size(); ++i)
  {
    points_[i] << in_cloud[i].x, in_cloud[i].y;
  }
  in_cloud_ = &in_cloud;
}

template <class CLOUD_IN_TYPE, class CLOUD_OUT_TYPE>
bool ConvexHull2D<CLOUD_IN_TYPE, CLOUD_OUT_TYPE>::MockConvexHull(CLOUD_OUT_TYPE *out_polygon)
{
  if (in_cloud_->size() == 0)
  {
    return false;
  }
  out_polygon->resize(4);
  Eigen::Matrix<double, 2, 1> max_v;
  Eigen::Matrix<double, 2, 1> min_v;
  max_v << in_cloud_->at(0).x, in_cloud_->at(0).y;
  min_v = max_v;
  for (std::size_t i = 1; i < in_cloud_->size(); ++i)
  {
    max_v(0) = std::max<double>(max_v(0), in_cloud_->at(i).x);
    max_v(1) = std::max<double>(max_v(1), in_cloud_->at(i).y);

    min_v(0) = std::min<double>(min_v(0), in_cloud_->at(i).x);
    min_v(1) = std::min<double>(min_v(1), in_cloud_->at(i).y);
  }

  static const double eps = 1e-3;
  for (std::size_t i = 0; i < 3; ++i)
  {
    if (max_v(i) - min_v(i) < eps)
    {
      max_v(i) += eps;
      min_v(i) -= eps;
    }
  }

  out_polygon->at(0).x = static_cast<float>(min_v(0));
  out_polygon->at(0).y = static_cast<float>(min_v(1));

  out_polygon->at(1).x = static_cast<float>(max_v(0));
  out_polygon->at(1).y = static_cast<float>(min_v(1));

  out_polygon->at(2).x = static_cast<float>(max_v(0));
  out_polygon->at(2).y = static_cast<float>(max_v(1));

  out_polygon->at(3).x = static_cast<float>(min_v(0));
  out_polygon->at(3).y = static_cast<float>(max_v(1));
  return true;
}

template <class CLOUD_IN_TYPE, class CLOUD_OUT_TYPE>
bool ConvexHull2D<CLOUD_IN_TYPE, CLOUD_OUT_TYPE>::GetConvexHullMonotoneChain(CLOUD_OUT_TYPE *out_polygon)
{
  if (points_.size() < 3)
  {
    return false;
  }

  std::vector<std::size_t> sorted_indices(points_.size());
  std::iota(sorted_indices.begin(), sorted_indices.end(), 0); // 用0开始的连续整数填充向量

  static const double eps = 1e-9;
  // sort by x, if have same x, by y
  std::sort(sorted_indices.begin(), sorted_indices.end(),
            [&](const std::size_t &lhs, const std::size_t &rhs) {
              double dx = points_[lhs](0) - points_[rhs](0);
              if (std::abs(dx) > eps)
              {
                return dx < 0.0;
              }
              return points_[lhs](1) < points_[rhs](1);
            });
  int count      = 0;
  int last_count = 1;
  polygon_indices_.clear();
  polygon_indices_.reserve(points_.size());

  std::size_t size2 = points_.size() * 2;
  for (std::size_t i = 0; i < size2; ++i)
  {
    if (i == points_.size())
    {
      last_count = count;
    }
    const std::size_t &idx = sorted_indices[(i < points_.size()) ? i : (size2 - 1 - i)];
    const auto &point      = points_[idx];
    while (count > last_count
           && !IsCounterClockWise(points_[polygon_indices_[count - 2]],
                                  points_[polygon_indices_[count - 1]],
                                  point, eps))
    {
      polygon_indices_.pop_back();
      --count;
    }
    polygon_indices_.push_back(idx);
    ++count;
  }
  --count;
  polygon_indices_.pop_back();
  if (count < 3)
  {
    return false;
  }
  out_polygon->clear();
  out_polygon->resize(polygon_indices_.size());

  for (std::size_t i = 0; i < polygon_indices_.size(); ++i)
  {
    out_polygon->at(i).x = static_cast<float>(points_[polygon_indices_[i]](0));
    out_polygon->at(i).y = static_cast<float>(points_[polygon_indices_[i]](1));
  }
  return true;
}

#endif
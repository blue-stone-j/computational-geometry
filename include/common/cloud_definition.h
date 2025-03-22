#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "common/point_definition.h"
#include <limits>
#include <vector>

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

template class PointCloud<Point2D<float>>;

#endif
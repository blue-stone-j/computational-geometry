#ifndef CONVEX_HULL_2D
#define CONVEX_HULL_2D

#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>

#include "Eigen/Dense"

#include "common/point_definition.h"
#include "common/cloud_definition.h"
#include "common/point_definition.h"

/* from Apollo 6.0 */


template struct Point2D<float>;


template <class CLOUD_IN_TYPE, class CLOUD_OUT_TYPE>
class ConvexHull2D
{
 public:
  ConvexHull2D();
  ~ConvexHull2D() { in_cloud_ = nullptr; }

  // main interface to get polygon from input point cloud
  bool GetConvexHull(const CLOUD_IN_TYPE &in_cloud, CLOUD_OUT_TYPE *out_polygon);

  // main interface to get polygon from input point cloud(without ground points)
  bool GetConvexHullWithoutGround(const CLOUD_IN_TYPE &in_cloud,
                                  const float &distance_above_ground_threshold,
                                  CLOUD_OUT_TYPE *out_polygon);

  // main interface to get polygon from input point cloud
  // (without ground points and points above the head of self-driving car)
  bool GetConvexHullWithoutGroundAndHead(const CLOUD_IN_TYPE &in_cloud, const float &distance_above_ground_threshold,
                                         const float &distance_beneath_head_threshold, CLOUD_OUT_TYPE *out_polygon);

 private:
  // save points in local memory, and transform to double
  void SetPoints(const CLOUD_IN_TYPE &in_cloud);

  // mock a polygon for some degenerate cases
  bool MockConvexHull(CLOUD_OUT_TYPE *out_polygon);

  // compute convex hull using Andrew's monotone chain algorithm
  bool GetConvexHullMonotoneChain(CLOUD_OUT_TYPE *out_polygon);

  // given 3 ordered points, return true if in counter clock wise.
  bool IsCounterClockWise(const Eigen::Vector2d &p1, const Eigen::Vector2d &p2,
                          const Eigen::Vector2d &p3, const double &eps);

 private:
  std::vector<Eigen::Vector2d> points_;
  std::vector<std::size_t> polygon_indices_;
  const CLOUD_IN_TYPE *in_cloud_;
};


template class ConvexHull2D<PointCloud<Point2D<float>>, PointCloud<Point2D<float>>>;


#endif
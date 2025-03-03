
#include <iostream>

#include "convex_hull/convex_hull2d.h"
#include "src/convex_hull/convex_hull2d.hpp"

typedef Point2D<float> PointF;
typedef PointCloud<PointF> PointFCloud;

int main()
{
  ConvexHull2D<PointFCloud, PointFCloud> convex_hull_2d;
  PointFCloud pointcloud_in, pointcloud_out;
  bool flag = true;
  flag      = convex_hull_2d.GetConvexHull(pointcloud_in, &pointcloud_out);

  PointF pt;
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 10; j++)
    {
      pt.x = static_cast<float>(i);
      pt.y = static_cast<float>(j);

      pointcloud_in.push_back(pt);
    }
  }
  flag = convex_hull_2d.GetConvexHull(pointcloud_in, &pointcloud_out);
  for (auto &pt : pointcloud_out.points)
  {
    std::cout << pt.x << ", " << pt.y << std::endl;
  }


  flag = false;
  pointcloud_out.clear();
  float distance_above_ground_threshold = -1.0f;
  flag                                  = convex_hull_2d.GetConvexHullWithoutGround(pointcloud_in,
                                                   distance_above_ground_threshold,
                                                   &pointcloud_out);


  pointcloud_out.clear();
  float distance_beneath_head_threshold = 10.0f;

  flag = convex_hull_2d.GetConvexHullWithoutGroundAndHead(pointcloud_in,
                                                          distance_above_ground_threshold,
                                                          distance_beneath_head_threshold,
                                                          &pointcloud_out);

  distance_above_ground_threshold = 10.0f;
  distance_beneath_head_threshold = -10.0f;
  pointcloud_out.clear();
  flag = convex_hull_2d.GetConvexHullWithoutGround(pointcloud_in,
                                                   distance_above_ground_threshold,
                                                   &pointcloud_out);

  pointcloud_out.clear();
  flag = convex_hull_2d.GetConvexHullWithoutGroundAndHead(pointcloud_in,
                                                          distance_above_ground_threshold,
                                                          distance_beneath_head_threshold,
                                                          &pointcloud_out);



  distance_above_ground_threshold = -10.0f;
  distance_beneath_head_threshold = 10.0f;
  pt.x                            = 15.5f;
  pt.y                            = 5.5f;
  pointcloud_in.push_back(pt);
  pointcloud_out.clear();
  flag = convex_hull_2d.GetConvexHullWithoutGround(pointcloud_in,
                                                   distance_above_ground_threshold,
                                                   &pointcloud_out);


  pointcloud_out.clear();
  flag = convex_hull_2d.GetConvexHullWithoutGroundAndHead(pointcloud_in,
                                                          distance_above_ground_threshold,
                                                          distance_beneath_head_threshold,
                                                          &pointcloud_out);



  return 0;
}
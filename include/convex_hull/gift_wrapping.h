// File: gift_wrapping.h
// Implement the gift wrapping algorithm to find the convex hull of a set of points in 2D space.
// 1. define a class GiftWrapping

#ifndef GIFT_WRAPPING_H
#define GIFT_WRAPPING_H


#include <vector>

#include "common/point_definition.h"

class GiftWrapping
{
 public:
  static std::vector<Point2D<float>> convex_hull(std::vector<Point2D<float>> &points);
};

#endif
// File: gift_wrapping.cpp

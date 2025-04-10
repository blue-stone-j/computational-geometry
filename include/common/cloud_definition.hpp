#ifndef CLOUD_DEFINITION_HPP
#define CLOUD_DEFINITION_HPP

#include "cloud_definition.h"

template <typename PointT>
void PointCloud<PointT>::push_back(PointT pt, float height)
{
  points.push_back(pt);
  points_height.push_back(height);
}

template <typename PointT>
void PointCloud<PointT>::emplace_back(PointT pt, float height)
{
  points.emplace_back(pt);
  points_height.emplace_back(height);
}

template <typename PointT>
void PointCloud<PointT>::clear()
{
  points.clear();
  points_height.clear();
}

template <typename PointT>
void PointCloud<PointT>::resize(size_t size)
{
  points.resize(size);
  points_height.resize(size, std::numeric_limits<float>::max());
}

template <typename PointT>
void PointCloud<PointT>::reserve(size_t size)
{
  points.reserve(size);
  points_height.reserve(size);
}

template <typename PointT>
PointT &PointCloud<PointT>::at(size_t pos)
{
  return points[pos];
}

template <typename PointT>
const PointT &PointCloud<PointT>::at(size_t pos) const
{
  return points[pos];
}

template <typename PointT>
PointT &PointCloud<PointT>::operator[](size_t pos)
{
  return points[pos];
}

template <typename PointT>
const PointT &PointCloud<PointT>::operator[](size_t pos) const
{
  return points[pos];
}

#endif
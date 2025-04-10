#include <algorithm>
#include "arc/min_arc.h"

template <typename Scalar>
MinArc<Scalar>::MinArc() :
  start_angle_(0), end_angle_(0), max_gap_index_(-1), arc_range_(0)
{
}

template <typename Scalar>
MinArc<Scalar>::~MinArc()
{
}

template <typename Scalar>
void MinArc<Scalar>::setInputAngles(const std::vector<std::pair<int, Scalar>> &angles)
{
  angles_ = angles;
}

template <typename Scalar>
void MinArc<Scalar>::addAngle(const Scalar &angle)
{
  angles_.push_back(std::pair<int, Scalar>(angles_.size(), angle));
}

template <typename Scalar>
Scalar MinArc<Scalar>::getStartAngle() const
{
  return start_angle_;
}

template <typename Scalar>
Scalar MinArc<Scalar>::getEndAngle() const
{
  return end_angle_;
}

template <typename Scalar>
std::pair<Scalar, Scalar> MinArc<Scalar>::getArcAngles() const
{
  return std::make_pair(start_angle_, end_angle_);
}

template <typename Scalar>
int MinArc<Scalar>::getLastIndex() const
{
  return angles_[max_gap_index_].first;
}

template <typename Scalar>
Scalar MinArc<Scalar>::getArcRange() const
{
  return arc_range_;
}

template <typename Scalar>
int MinArc<Scalar>::process()
{
  if (angles_.empty())
  {
    return 1;
  }

  // 按角度排序
  std::sort(angles_.begin(), angles_.end(), [](const std::pair<int, Scalar> &a, const std::pair<int, Scalar> &b) { return a.second < b.second; });
  std::vector<double> angles(angles_.size(), 0);
  for (size_t i = 0; i < angles_.size(); i++)
  {
    angles[i] = angles_[i].second;
  }
  // 寻找最大间隔
  double max_gap = 0;
  for (size_t i = 0; i < angles.size(); ++i)
  {
    double gap = i == angles.size() - 1 ?
                     angles[0] + 2 * M_PI - angles[i] : // 循环到第一个点
                     angles[i + 1] - angles[i];
    if (gap > max_gap)
    {
      max_gap        = gap;
      max_gap_index_ = i;
    }
  }

  // 计算圆弧的起点和终点角度
  start_angle_ = (max_gap_index_ == angles.size() - 1) ? angles[0] : angles[max_gap_index_ + 1];
  end_angle_   = angles[max_gap_index_];

  arc_range_ = end_angle_ - start_angle_;
  if (arc_range_ < 0)
  {
    arc_range_ += 2 * M_PI;
  }

  return 0;
}
// File: min_arc.h
// Input angles and find the minimum arc to cover all the angles. Angles are in radians and in the range of [0, 2*pi)
// 1. define a class MinArc
// 2. define public methods: setInputAngles, process, getStartAngle, getEndAngle, getArcAngles
// 3. define private members: angles_, start_angle_, end_angle_
// 4. define public template class MinArc<float> and MinArc<double>

#ifndef MIN_ARC_H
#define MIN_ARC_H

#include <cmath>
#include <utility>
#include <vector>

template <typename Scalar>
class MinArc
{
 public:
  MinArc();
  ~MinArc();
  void setInputAngles(const std::vector<std::pair<int, Scalar>> &angles);
  void addAngle(const Scalar &angle);
  int process();
  Scalar getStartAngle() const;
  Scalar getEndAngle() const;
  std::pair<Scalar, Scalar> getArcAngles() const;
  int getLastIndex() const;
  Scalar getArcRange() const;

 private:
  std::vector<std::pair<int, Scalar>> angles_;
  Scalar start_angle_;
  Scalar end_angle_;
  int max_gap_index_;
  Scalar arc_range_;
};

template class MinArc<float>;
template class MinArc<double>;

#endif
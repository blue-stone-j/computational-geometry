#ifndef ARC_UTILS_H
#define ARC_UTILS_H

#include <cmath>

// 将笛卡尔坐标转换为极坐标的角度（弧度制）[0-2PI]
template <typename Scalar>
inline double getAngle(Scalar x, Scalar y)
{
  double angle = std::atan2(y, x);
  // 保证角度为正
  if (angle < 0)
  {
    angle += 2 * M_PI;
  }
  return angle;
}

#endif
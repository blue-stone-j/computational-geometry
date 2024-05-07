#ifndef MIN_ARC_H
#define MIN_ARC_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 将笛卡尔坐标转换为极坐标的角度（弧度制）[0-2PI]
double getAngle(double x, double y)
{
  double angle = atan2(y, x);
  // 保证角度为正
  if (angle < 0)
  {
    angle += 2 * M_PI;
  }
  return angle;
}

#endif
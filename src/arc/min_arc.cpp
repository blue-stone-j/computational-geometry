#include "arc/min_arc.h"

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
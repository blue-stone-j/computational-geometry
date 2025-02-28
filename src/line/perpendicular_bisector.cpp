
#include <iostream>

#include "line/perpendicular_bisector.h"


// 计算中点
Point findMidpoint(const Point &A, const Point &B)
{
  return {(A.x + B.x) / 2, (A.y + B.y) / 2};
}

// 计算中垂线
void findPerpendicularBisector(const Point &A, const Point &B)
{
  Point M = findMidpoint(A, B);
  double slope;

  // 判断线段是否垂直
  if (A.x == B.x)
  {
    std::cout << "中垂线方程是 x = " << M.x << std::endl;
  }
  else
  {
    slope                     = (B.y - A.y) / (B.x - A.x);
    double perpendicularSlope = -1 / slope;
    // 使用点斜式方程 y - y1 = m(x - x1)
    std::cout << "中垂线方程是 y - " << M.y << " = " << perpendicularSlope << "(x - " << M.x << ")" << std::endl;
  }
}
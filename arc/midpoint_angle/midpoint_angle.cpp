#include <iostream>
#include <cmath>

// 将角度标准化到[0, 2π]范围
double normalizeAngle(double angle)
{
  while (angle < -M_PI) angle += 2 * M_PI;
  while (angle >= M_PI) angle -= 2 * M_PI;
  return angle;
}

// 计算较短圆弧中点对应的角度
double calculateMidpointAngle(double theta1, double theta2)
{
  // 标准化角度
  theta1 = normalizeAngle(theta1);
  theta2 = normalizeAngle(theta2);

  // 确定是否需要通过圆的另一侧计算中点
  if (fabs(theta2 - theta1) > M_PI)
  {
    if (theta2 > theta1)
    {
      theta1 += 2 * M_PI;
    }
    else
    {
      theta2 += 2 * M_PI;
    }
  }

  // 计算并标准化中点角度
  double midAngle = (theta1 + theta2) / 2.0;
  return normalizeAngle(midAngle);
}

int main( )
{
  // 示例：θ1 = 0, θ2 = π / 2
  double theta1   = -M_PI + 0.2;
  double theta2   = M_PI - 0.1;
  double midAngle = calculateMidpointAngle(theta1, theta2);

  std::cout << "Midpoint Angle: " << midAngle << " radians" << std::endl;

  return 0;
}

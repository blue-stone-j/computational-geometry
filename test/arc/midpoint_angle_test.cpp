
#include <iostream>

#include "arc/midpoint_angle.h"


int main()
{
  double midAngle;

  // two angles
  double theta1 = -M_PI + 0.2;
  double theta2 = M_PI - 0.1;
  midAngle      = calculateMidpointAngle(theta1, theta2);
  std::cout << "Midpoint Angle: " << midAngle << " radians" << std::endl;

  // many angles
  std::vector<double> angles;
  angles.push_back(theta1);
  angles.push_back(theta2);
  midAngle = calculateAverageAngle(angles);
  std::cout << "Midpoint Angle: " << midAngle << " radians" << std::endl;

  return 0;
}
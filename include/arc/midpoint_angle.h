#ifndef MIDPOINT_ANGLE_H
#define MIDPOINT_ANGLE_H

#include <cmath>
#include <vector>

// 将角度标准化到[0, 2π]范围
double normalizeAngle(double angle);

// 计算较短圆弧中点对应的角度
double calculateMidpointAngle(double theta1, double theta2);

double calculateAverageAngle(const std::vector<double> &angles);
#endif
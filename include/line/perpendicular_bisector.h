#include <iostream>
using namespace std;

struct Point
{
  double x, y;
};

// 计算中点
Point findMidpoint(const Point &A, const Point &B);

// 计算中垂线
void findPerpendicularBisector(const Point &A, const Point &B);

#include <iostream>
#include <vector>
#include <algorithm>

#include "arc/arc_utils.h"
#include "arc/min_arc.h"
#include "src/arc/min_arc.cpp"

// 主程序
int main()
{
  // 假设三个点的坐标
  std::vector<std::pair<double, double>> points = {
      {1.0, 0.0}, // 点A
      {0, 1},     // 点B
      {0, -1}     // 点C
  };

  std::vector<std::pair<int, double>> angles_vec;
  for (size_t i = 0; i < points.size(); i++)
  {
    angles_vec.push_back(std::pair<int, double>(i, getAngle(points[i].first, points[i].second)));
  }

  MinArc<double> min_arc;
  min_arc.setInputAngles(angles_vec);
  min_arc.process();
  double start_angle = min_arc.getStartAngle();
  double end_angle   = min_arc.getEndAngle();
  int last_index     = min_arc.getLastIndex();

  // 打印结果
  std::cout << "Arc Start Angle (radians): " << start_angle << std::endl;
  std::cout << "Arc End Angle (radians): " << end_angle << std::endl;

  // 如果需要，可以转换为度
  std::cout << "Arc Start Angle (degrees): " << start_angle * (180.0 / M_PI) << std::endl;
  std::cout << "Arc End Angle (degrees): " << end_angle * (180.0 / M_PI) << std::endl;

  // 或者计算并打印起点和终点的笛卡尔坐标
  std::cout << "Arc Start Point: (" << cos(start_angle) << ", " << sin(start_angle) << ")" << std::endl;
  std::cout << "Arc End Point: (" << cos(end_angle) << ", " << sin(end_angle) << ")" << std::endl;

  // index of last point in this arc
  std::cout << "id: " << last_index << std::endl;

  return 0;
}

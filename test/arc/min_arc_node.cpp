#include "arc/min_arc.h"

// 主程序
int main( )
{
  // 假设三个点的坐标
  std::vector<std::pair<double, double>> points = {
      {1.0, 0.0}, // 点A
      {0, 1},     // 点B
      {0, -1}     // 点C
  };

  std::vector<std::pair<int, double>> angles_vec;
  for (size_t i = 0; i < points.size( ); i++)
  {
    angles_vec.push_back(std::pair<int, double>(i, getAngle(points[i].first, points[i].second)));
  }

  // 按角度排序
  std::sort(angles_vec.begin( ), angles_vec.end( ), [](const std::pair<int, double> &a, const std::pair<int, double> &b) { return a.second < b.second; });
  std::vector<double> angles(points.size( ), 0);
  for (size_t i = 0; i < angles_vec.size( ); i++)
  {
    angles[i] = angles_vec[i].second;
  }
  // 寻找最大间隔
  double maxGap   = 0;
  int maxGapIndex = -1;
  for (size_t i = 0; i < angles.size( ); ++i)
  {
    double gap = i == angles.size( ) - 1 ?
                     angles[0] + 2 * M_PI - angles[i] : // 循环到第一个点
                     angles[i + 1] - angles[i];
    if (gap > maxGap)
    {
      maxGap      = gap;
      maxGapIndex = i;
    }
  }

  // 计算圆弧的起点和终点角度
  double startAngle = maxGapIndex == angles.size( ) - 1 ? angles[0] : angles[maxGapIndex + 1];
  double endAngle   = angles[maxGapIndex];

  // 打印结果
  std::cout << "Arc Start Angle (radians): " << startAngle << std::endl;
  std::cout << "Arc End Angle (radians): " << endAngle << std::endl;

  // 如果需要，可以转换为度
  std::cout << "Arc Start Angle (degrees): " << startAngle * (180.0 / M_PI) << std::endl;
  std::cout << "Arc End Angle (degrees): " << endAngle * (180.0 / M_PI) << std::endl;

  // 或者计算并打印起点和终点的笛卡尔坐标
  std::cout << "Arc Start Point: (" << cos(startAngle) << ", " << sin(startAngle) << ")" << std::endl;
  std::cout << "Arc End Point: (" << cos(endAngle) << ", " << sin(endAngle) << ")" << std::endl;

  // index of last point in this arc
  std::cout << "id: " << angles_vec[maxGapIndex].first << std::endl;

  return 0;
}

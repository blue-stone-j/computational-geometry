#include "convex_hull/gift_wrapping.h"

// Cross product of vectors p0p1 and p0p2
int cross(const Point2D<float> &p0, const Point2D<float> &p1, const Point2D<float> &p2)
{
  return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

// Find the point with the lowest y (break ties with lowest x)
int leftmost_point(const std::vector<Point2D<float>> &points)
{
  int idx = 0;
  for (int i = 1; i < points.size(); ++i)
  {
    if (points[i].x < points[idx].x || (points[i].x == points[idx].x && points[i].y < points[idx].y))
    {
      idx = i;
    }
  }
  return idx;
}

// Jarvis March (Gift Wrapping) algorithm
std::vector<Point2D<float>> convexHull(const std::vector<Point2D<float>> &points)
{
  int n = points.size();
  if (n < 3) return points;

  std::vector<Point2D<float>> hull;
  int l = leftmost_point(points);
  int p = l, q;

  do
  {
    hull.push_back(points[p]);
    q = (p + 1) % n;

    for (int i = 0; i < n; ++i)
    {
      if (cross(points[p], points[i], points[q]) > 0)
        q = i;
    }

    p = q;
  } while (p != l);

  return hull;
}

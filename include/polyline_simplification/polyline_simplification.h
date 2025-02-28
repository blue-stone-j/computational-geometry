#ifndef POLY_SIMPLIFY_H
#define POLY_SIMPLIFY_H

#include <vector>
#include <math.h>
#include <json/json.h>

struct Point3D
{
  Point3D(double xi = 0, double yi = 0, double zi = 0) :
    x(xi), y(yi), z(zi)
  {
  }

  double x;
  double y;
  double z;
};

class PolylineSimplification
{
 public:
  std::vector<Point3D> poly, poly_s;

  double getDistancePointToPoint(Point3D p1, Point3D p2);

  bool pointsEqual(Point3D p1, Point3D p2);

  // read polyline
  int readPoly(std::string file);

  // save polyline
  int writePoly(std::string file);

  void setPoly(std::vector<Point3D> &points_in);

  virtual int simplifyBase() = 0;

  double tolerance = 0.5;
};

class RadialDistance : public PolylineSimplification
{
 public:
  int simplifyBase();

 private:
};

class PerpendicularDistance : public PolylineSimplification
{
 private:
  double perpendDis(const Point3D &point, const Point3D &lineStart, const Point3D &lineEnd);

 public:
  int simplifyBase();
};

class DouglasPeucker : public PolylineSimplification
{
 public:
  int simplifyBase();

  std::vector<Point3D> simplifyDPStep(std::vector<Point3D> points, int first, int last, double tolerance,
                                      std::vector<Point3D> simplified);

  double getDistancePointToSegment(Point3D p, Point3D p1, Point3D p2);
};

#endif
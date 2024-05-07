#ifndef POLY_SIMPLIFY_H
#define POLY_SIMPLIFY_H

#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <json/json.h>

typedef struct Point3D
{
  Point3D(double xi = 0, double yi = 0, double zi = 0) :
    x(xi), y(yi), z(zi)
  {
  }

  double x;
  double y;
  double z;
} Point3D;

class PolylineSimplification
{
 public:
  std::vector<Point3D> poly, poly_s;

  double getDistancePointToPoint(Point3D p1, Point3D p2)
  {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
  }
  bool pointsEqual(Point3D p1, Point3D p2)
  {
    return std::abs(p1.x - p2.x) < 0.01 && std::abs(p1.y - p2.y) < 0.01 && std::abs(p1.z - p2.z) < 0.01;
  }

  // read polyline
  int readPoly(std::string file)
  {
    if (file.empty( ))
    {
      std::cout << "Please specify polyline file!" << std::endl;
      return 1;
    }
    std::ifstream fs;
    fs.open(file);
    if (!fs.is_open( ))
    {
      std::cout << "can't open " << file << std::endl;
      return 2;
    }
    if (!fs)
    {
      std::cout << "error: " << file << std::endl;
      return 3;
    }

    Json::Value root; // 将会包含根节点
    Json::Reader reader;
    if (!reader.parse(fs, root, false))
    {
      std::cerr << "Failed to parse the poly file." << std::endl;
      return 4;
    }

    poly.clear( );
    for (int i = 0; i < root.size( ); ++i)
    {
      const Json::Value &pt = root[i];
      poly.push_back(Point3D(pt["x"].asDouble( ), pt["y"].asDouble( ), pt["z"].asDouble( )));
    }

    std::cout << "size of poly: " << poly.size( ) << std::endl;

    return 0;
  }
  // save polyline
  int writePoly(std::string file)
  {
    if (file.empty( ))
    {
      std::cout << "Please specify polyline file!" << std::endl;
      return 1;
    }
    std::cout << "size of ps: " << poly_s.size( ) << std::endl;

    Json::Value root;
    for (int i = 0; i < poly_s.size( ); i++)
    {
      Json::Value pt;
      pt["x"] = poly_s[i].x;
      pt["y"] = poly_s[i].y;
      pt["z"] = poly_s[i].z;
      root.append(pt);
    }

    std::ofstream fs;
    fs.open(file);
    Json::StyledWriter styledWriter;
    fs << styledWriter.write(root);
    fs.close( );

    return 0;
  }
  void setPoly(std::vector<Point3D> &points_in)
  {
    poly = points_in;
  }

  virtual int simplifyBase( ) = 0;
};

class RadialDistance : public PolylineSimplification
{
 public:
  int simplifyBase( )
  {
    poly_s.clear( );
    if (poly.size( ) < 2)
    {
      poly_s = poly;
      return 0;
    }
    Point3D prevPoint, point;
    double sqDistance = 0.0;
    size_t n          = poly.size( );
    prevPoint         = poly.front( );
    poly_s.push_back(prevPoint);

    for (size_t i = 1; i < n; i++)
    {
      point      = poly[i];
      sqDistance = getDistancePointToPoint(point, prevPoint);
      if (sqDistance > tolerrance)
      {
        poly_s.push_back(point);
        prevPoint = point;
      }
    }

    // whether last point is excluded
    if (!pointsEqual(prevPoint, point))
    {
      poly_s.push_back(point);
    }
    return 0;
  }

 private:
  double tolerrance = 0.5;
};

class PerpendicularDistance : public PolylineSimplification
{
 private:
  double tolerrance = 0.5;
  double perpendDis(const Point3D &point, const Point3D &lineStart, const Point3D &lineEnd)
  {
    double dx  = lineEnd.x - lineStart.x;
    double dy  = lineEnd.y - lineStart.y;
    double dz  = lineEnd.z - lineStart.z;
    double mag = std::sqrt(dx * dx + dy * dy + dz * dz);
    if (mag < 0.00001)
    {
      return std::sqrt((point.x - lineStart.x) * (point.x - lineStart.x)
                       + (point.y - lineStart.y) * (point.y - lineStart.y)
                       + (point.z - lineStart.z) * (point.z - lineStart.z));
    }
    double u = ((point.x - lineStart.x) * dx + (point.y - lineStart.y) * dy + (point.z - lineStart.z) * dz) / (mag * mag);
    Point3D intersect(lineStart.x + u * dx, lineStart.y + u * dy, lineStart.z + u * dz);
    return std::sqrt((point.x - intersect.x) * (point.x - intersect.x)
                     + (point.y - intersect.y) * (point.y - intersect.y)
                     + (point.z - intersect.z) * (point.z - intersect.z));
  }

 public:
  int simplifyBase( )
  {
    poly_s.clear( );
    if (poly.size( ) < 2)
    {
      poly_s = poly;
      return 0;
    }
    // poly_s.push_back(poly[0]);
    std::vector<Point3D> tem(3);
    double dis = 1000;
    for (size_t i = 2; i < poly.size( ); i++)
    {
      if (dis < tolerrance)
      {
        tem[1] = poly[i - 1];
        tem[2] = poly[i];
      }
      else
      {
        tem[0] = poly[i - 2];
        tem[1] = poly[i - 1];
        tem[2] = poly[i];
        poly_s.push_back(tem[0]);
      }

      dis = perpendDis(tem[1], tem[0], tem[2]);
    }

    if (dis > tolerrance)
    {
      poly_s.push_back(tem[1]);
    }
    poly_s.push_back(tem[2]);

    return 0;
  }
};

class DouglasPeucker : public PolylineSimplification
{
 public:
  int simplifyBase( )
  {
    return 0;
  }
};

#endif
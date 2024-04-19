#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <json/json.h>

/*
 This code was developed by Alan Soares
 Github - https://github.com/alanssoares
*/

typedef struct Point3D
{
  Point3D(double xi = 0, double yi = 0, double zi = 0) :
    x(xi), y(yi), z(zi)
  {}

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
 public:
  int simplifyBase( )
  {
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

int main(int argc, char const *argv[])
{
  // std::vector<Point3D> points;
  int mode = 0;
  if (argc > 1)
  {
    mode = std::atoi(argv[1]);
  }
  PolylineSimplification *ps;
  switch (mode)
  {
    case 0:
      ps = new RadialDistance( );
      break;
    case 1:
      ps = new PerpendicularDistance( );
      break;
    case 2:
      ps = new DouglasPeucker( );
      break;
    default:
      ps = new RadialDistance( );
      break;
  }

  ps->readPoly("../polyline_simplification/poly.json");

  ps->simplifyBase( );

  ps->writePoly("../polyline_simplification/ps.json");
  return 0;
}
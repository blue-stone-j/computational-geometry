#include "polyline_simplification/polyline_simplification.h"


int main(int argc, char const *argv[])
{
  // std::vector<Point3D> points;
  int mode = 1;
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

  ps->readPoly("../assets/polyline_simplification/poly.json");

  ps->simplifyBase( );

  ps->writePoly("../assets/polyline_simplification/ps.json");

  return 0;
}
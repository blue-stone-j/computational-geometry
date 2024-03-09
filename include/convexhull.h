#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include <QVector>
#include <QVector3D>
#include <QList>
#include "sort.h"
#include <QDebug>
extern bool cmpXandY(Point p1, Point p2);
extern bool cmpXsubY(Point p1, Point p2);
class ConvexHull
{
  bool IsLeftPoint(Point pt, Line line);
  bool IsRightPoint(Point pt, Line line);
  float Cross2D(Point a, Point b);
  QList<Point> hullpts;  // 保存凸包点
  QList<Point> dispts;   // 保存离散点=所有点-凸包点
  QList<Triangle> tins;  // 保存三角形
  QVector<Line> vnlines; // voronoi lines
  QVector<Point> vnpts;  // voronoi points

 public:
  ConvexHull( );
  void generateHull(QVector<Point> pts);
  QList<Triangle> DivideHull(QList<Point> pts);
  QList<Triangle> DivideHull( );
  QList<Point> getHull( ) { return hullpts; }
  QList<Triangle> getTins( ) const;
  QList<Triangle> getDelaunay(QList<Triangle> hulltins, QList<Point> pts);
  QList<Point> getDispts( ) const;

  void generateVoronoi( );
  QVector<Line> getVoronoiLines( );
  QVector<Point> getVoronoiPoints( );
};

#endif // CONVEXHULL_H

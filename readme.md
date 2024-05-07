### introduction
Some algorithms about computional geometry.

### package type
Dependent packages will be compiled in its folder and independent package will be compiled in root folder.

### assets
Local resources are stored in folder `assets_local`, where resources are used only this repositories. Global resources are stored in folder `assets`, where resources also are used in other repositories. This folder is a git submodule, which means it's a seperate git repository and therefore, it won't enlarge git of current repository.

### dependency
* cmake
* ros-json-cpp
* 

### compile and run 
<!-- Before you compile and run, recommand to update assets.
```bash
cd assets
git pull
``` -->
For independent packages, take `min_arc` as example
```bash
mkdir -p build
cd build
cmake ..
make
./min_arc
```

### delaunay
This is a dependent package about delaunay and volonoi. It provides a GUI to display delaunay triangulation and volonoi using qt. You can run it as `README.md` in this package.
```bash
cd delaunay
mkdir -p build
cd build
cmake ..
make
./delaunay
```

### arc
These aren't a dependent package. Some algorithms about arc.
##### midpoint_angle
Calculate midpoint of two points on a circle.

##### min_arc
It can calculate a minimal arc that cover three points on a circle.

### polyline_simplification
These aren't a dependent package to simplify poliline. A algorithm to reduce vertice of polyline.
`generate_polyline.py` is used to generate polyline and `draw_polyline.py` is used to draw polyline.

```bash
# generate polyline
cd polyline_simplification
python3 generate_polyline.py
# compile and run
cd ..
mkdir -p build
cd build
cmake ..
make
./polyline_simplification
# draw simplified polyline
cd ../polyline_simplification
python3 draw_polyline
```

##### radial_distance
Keep only one point in an circular area.

##### perpendicular_distance

##### douglas_peucker

### line
Algorithms about line.

##### perpendicular_bisector
Method to calculate perpendicular bisector of line segment.
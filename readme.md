### introduction
Some algorithms about computional geometry.

### package type
Dependent packages will be compiled in its folder and independent package will be compiled in root folder.

### asserts
Local resources are stored in folder `asserts_local`, where resources are used only this repositories. Global resources are stored in folder `asserts`, where resources also are used in other repositories. This folder is a git submodule, which means it's a seperate git repository and therefore, it won't enlarge git of current repository.

### dependency
* cmake
* 
* 

### compile and run 
Before you compile and run, recommand to update asserts.
```bash
cd asserts
git pull
```
For dependent packages, take `delaunay` as example
```bash
cd delaunay
mkdir -p build
cd build
cmake ..
make
./delaunay
```
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

### arc
These aren't a dependent package. Some algorithms about arc.

### polyline_simplification
These aren't a dependent package to simplify poliline. A algorithm to reduce vertice of polyline.

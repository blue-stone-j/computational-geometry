# Delaunay

### source
1. source: https://github.com/kaiwu119/Delaunay

### commit
1. replace qmake with cmake.
2. add notes
3. improve code structure
4. add voronoi(code and ui)

### how to run
```bash
# get into folder
cd source_folder
# generate empty folder to store compilation file
mkdir build
# compile configuration
cmake ..
# compile
make install
# run
cd ../install
./delaunay
```
All necassary files and exe file are installed in folder `install`. You can move folder `install` to other place and then use it.

### algorithm
Bowyer-Watson算法用于生成Delaunay三角剖分。其基本思想是逐点添加到图中，对于每个新点，删除所有使得新点落在其外接圆内的三角形，然后将新点与其可见边界的顶点连接起来。


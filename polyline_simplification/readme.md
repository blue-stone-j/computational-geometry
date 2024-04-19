`generate_polyline.py` is used to generate polyline and `draw_polyline.py` is used to draw polyline.

Some code is based on [Alan Soares](https://github.com/alanssoares). 

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

### radial_distance

### perpendicular_distance

### douglas_peucker


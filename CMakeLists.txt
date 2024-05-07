cmake_minimum_required(VERSION 3.16.3)
project(com_geo)

set(CMAKE_BUILD_TYPE "Release")
add_compile_options(-std=c++17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(PkgConfig)
pkg_check_modules(JSONCPP jsoncpp)

include_directories(
  include

  ${JSONCPP_INCLUDE_DIRS}
)

# set(TARGET_LIBRARIES "")
# list(APPEND TARGET_LIBRARIES ${PCL_LIBRARIES})
add_executable(min_arc test/arc/min_arc_node.cpp)
add_executable(midpoint_angle test/arc/midpoint_angle_node.cpp)

add_executable(perpendicular_bisector test/line/perpendicular_bisector_node.cpp)

add_executable(polyline_simplification test/polyline_simplification/polyline_simplification_node.cpp)
target_link_libraries(polyline_simplification ${JSONCPP_LIBRARIES})

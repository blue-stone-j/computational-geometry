cmake_minimum_required(VERSION 3.16.3)
project(com_geo)

set(CMAKE_BUILD_TYPE "Release")
add_compile_options(-std=c++17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(Eigen3 REQUIRED)

# pkg-config 是一个在 UNIX-like 系统中广泛使用的计算机工具，它帮助在编译阶段自动从已安装的库中获取关于编译器和链接器选项的信息。
# 这个工具设计用于通过一个中心化的方式管理软件库的元数据，如版本、描述、编译器和链接器的标志等。
find_package(PkgConfig)

# 1. 查询库信息：使用 pkg-config 来获取 jsoncpp 库的信息，包括编译标志（CFLAGS）、链接标志（LIBS）等。
# 2. 设置变量：根据查询到的信息，CMake 会设置一系列变量，这些变量使用 JSONCPP 作为前缀。例如，JSONCPP_INCLUDE_DIRS、JSONCPP_LIBRARY_DIRS 和 JSONCPP_LIBRARIES。
pkg_check_modules(JSONCPP jsoncpp)

message(NOTICE ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(min_arc test/arc/min_arc_node.cpp)
target_include_directories(min_arc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(midpoint_angle test/arc/midpoint_angle_node.cpp)
target_include_directories(midpoint_angle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(perpendicular_bisector test/line/perpendicular_bisector_node.cpp)
target_include_directories(perpendicular_bisector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(polyline_simplification test/polyline_simplification/polyline_simplification_node.cpp)
target_include_directories(polyline_simplification PUBLIC ${JSONCPP_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(polyline_simplification ${JSONCPP_LIBRARIES})

add_executable(convex_hull2d test/convex_hull/convex_hull2d_node.cpp)
target_include_directories(convex_hull2d PUBLIC ${EIGEN3_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(convex_hull2d Eigen3::Eigen)

add_executable(alpha_shape test/alpha_shape_node.cpp src/alpha_shape.cpp)
target_include_directories(alpha_shape PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
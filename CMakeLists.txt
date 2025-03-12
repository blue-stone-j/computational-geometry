cmake_minimum_required(VERSION 3.16.3)
project(com_geo)

set(CMAKE_BUILD_TYPE "Release")
add_compile_options(-std=c++17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(Eigen3 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})

# pkg-config 是一个在 UNIX-like 系统中广泛使用的计算机工具，它帮助在编译阶段自动从已安装的库中获取关于编译器和链接器选项的信息。
# 这个工具设计用于通过一个中心化的方式管理软件库的元数据，如版本、描述、编译器和链接器的标志等。
find_package(PkgConfig)

# 1. 查询库信息：使用 pkg-config 来获取 jsoncpp 库的信息，包括编译标志（CFLAGS）、链接标志（LIBS）等。
# 2. 设置变量：根据查询到的信息，CMake 会设置一系列变量，这些变量使用 JSONCPP 作为前缀。例如，JSONCPP_INCLUDE_DIRS、JSONCPP_LIBRARY_DIRS 和 JSONCPP_LIBRARIES。
pkg_check_modules(JSONCPP jsoncpp)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/alpha_shape.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/arc.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/convex_hull.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/line.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/polyline_simplification.cmake)
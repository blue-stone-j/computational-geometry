cmake_minimum_required(VERSION 3.16.3)
project(com_geo)

set(CMAKE_BUILD_TYPE "Release")
add_compile_options(-std=c++17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# set(TARGET_LIBRARIES "")
# list(APPEND TARGET_LIBRARIES ${PCL_LIBRARIES})
add_executable(min_arc min_arc/min_arc.cpp)

# target_link_libraries(backtracking ${TARGET_LIBRARIES})

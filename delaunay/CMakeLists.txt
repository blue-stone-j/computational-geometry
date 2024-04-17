cmake_minimum_required(VERSION 3.10)
project(delaunay)

# set(ROS_VERSION $ENV{ROS_DISTRO})
include(FindPkgConfig)

# find_package(REQUIRED COMPONENTS
# )
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(OpenCV REQUIRED)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

find_package(GLUT REQUIRED)

# set(CMAKE_CXX_FLAGS "-O2 -Wall -g ${CMAKE_CXX_FLAGS}")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

EXECUTE_PROCESS(
  COMMAND pkg-config --variable=host_bins Qt5Core
  OUTPUT_VARIABLE Qt5BIN
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# # Specify additional locations of header files
# # Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  ${LIBXML2_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${GLUT_INCLUDE_DIRS}
)

qt5_wrap_cpp(MOC_FILES include/widget.h include/ui_widget.h)

# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(delaunay
  src/main.cpp
  src/widget.cpp
  src/convexhull.cpp
  src/sort.cpp
  src/kdtree.cpp
  ${MOC_FILES}
)

target_link_libraries(delaunay
  ${OPENGL_LIBRARIES}
  ${PCL_LIBRARIES}
  ${GLUT_LIBRARY}
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::OpenGL)

# message(FATAL_ERROR ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS delaunay
  DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/install
)

# build
install(DIRECTORY
  ${CMAKE_CURRENT_SOURCE_DIR}/asserts

  DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/install
)
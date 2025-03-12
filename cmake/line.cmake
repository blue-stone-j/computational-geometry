

add_executable(perpendicular_bisector test/line/perpendicular_bisector_test.cpp src/line/perpendicular_bisector.cpp)
target_include_directories(perpendicular_bisector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


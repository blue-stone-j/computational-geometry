
add_executable(convex_hull2d test/convex_hull/convex_hull2d_test.cpp)
target_include_directories(convex_hull2d PUBLIC ${EIGEN3_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(convex_hull2d Eigen3::Eigen)
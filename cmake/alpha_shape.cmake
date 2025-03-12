
add_executable(alpha_shape test/alpha_shape_test.cpp src/alpha_shape.cpp)
target_include_directories(alpha_shape PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
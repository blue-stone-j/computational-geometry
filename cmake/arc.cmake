
add_executable(min_arc test/arc/min_arc_test.cpp src/arc/min_arc.cpp)
target_include_directories(min_arc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(midpoint_angle test/arc/midpoint_angle_test.cpp src/arc/midpoint_angle.cpp)
target_include_directories(midpoint_angle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# if(BUILD_TEST)
#   add_executable(cylinder_node test/cylinder_node.cpp src/cylinder.cpp)
#   target_link_libraries(cylinder_node ${PCL_LIBRARIES})
# endif()
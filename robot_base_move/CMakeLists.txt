cmake_minimum_required(VERSION 2.8.3)
project(robot_base_move)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
  std_msgs
  geometry_msgs
  move_base_msgs
  tf
  message_generation

)

 add_service_files(
   FILES
   base_move.srv
 )

 generate_messages(
   DEPENDENCIES
   move_base_msgs
 )

catkin_package(
  INCLUDE_DIRS include
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/robot_base_move.cpp src/robot_base_move.h)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)


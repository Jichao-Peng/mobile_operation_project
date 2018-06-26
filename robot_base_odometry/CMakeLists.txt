cmake_minimum_required(VERSION 2.8.3)
project(robot_base_odometry)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  nav_msgs
  N_Robot_Topic
  N_Robot
  tf
)

find_package(Boost REQUIRED COMPONENTS system)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS} "/usr/include/eigen3/")

add_dependencies(${catkin_EXPORTED_TARGETS})

add_executable(robot_base_odometry_node src/robot_base_odometry.cpp src/robot_base_odometry.h)

target_link_libraries(robot_base_odometry_node ${catkin_LIBRARIES})

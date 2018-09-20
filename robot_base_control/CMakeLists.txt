cmake_minimum_required(VERSION 2.8.3)
project(robot_base_control)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  move_base_msgs
  roscpp
  std_srvs
  std_msgs
  cv_bridge
  message_generation
)

add_service_files(
   FILES
   base_goal.srv
)

generate_messages(
   DEPENDENCIES
   std_msgs
)


catkin_package(
  INCLUDE_DIRS include
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(${PROJECT_NAME}_node src/robot_base_control.cpp src/robot_base_control.h)

target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
 )



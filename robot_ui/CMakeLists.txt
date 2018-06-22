cmake_minimum_required(VERSION 2.8.3)
project(robot_ui)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rviz
  std_msgs
)


include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

add_definitions(-DQT_NO_KEYWORDS)

qt4_wrap_cpp(MOC_FILES src/robot_ui.h)

set(SOURCE_FILES src/robot_ui.cpp ${MOC_FILES})

add_library(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${catkin_LIBRARIES})

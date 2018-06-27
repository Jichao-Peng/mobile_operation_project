# Install script for directory: /home/robot2/catkin_ws/src/universal_robot/ur_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ur_msgs/msg" TYPE FILE FILES
    "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/Analog.msg"
    "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/Digital.msg"
    "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/IOStates.msg"
    "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/RobotStateRTMsg.msg"
    "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/MasterboardDataMsg.msg"
    "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/ToolDataMsg.msg"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ur_msgs/srv" TYPE FILE FILES
    "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/srv/SetPayload.srv"
    "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/srv/SetIO.srv"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ur_msgs/cmake" TYPE FILE FILES "/home/robot2/catkin_ws/src/cmake-build-debug/universal_robot/ur_msgs/catkin_generated/installspace/ur_msgs-msg-paths.cmake")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/robot2/catkin_ws/src/cmake-build-debug/devel/include/ur_msgs")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/robot2/catkin_ws/src/cmake-build-debug/devel/share/common-lisp/ros/ur_msgs")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/robot2/catkin_ws/src/cmake-build-debug/devel/lib/python2.7/dist-packages/ur_msgs")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/robot2/catkin_ws/src/cmake-build-debug/devel/lib/python2.7/dist-packages/ur_msgs")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/robot2/catkin_ws/src/cmake-build-debug/universal_robot/ur_msgs/catkin_generated/installspace/ur_msgs.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ur_msgs/cmake" TYPE FILE FILES "/home/robot2/catkin_ws/src/cmake-build-debug/universal_robot/ur_msgs/catkin_generated/installspace/ur_msgs-msg-extras.cmake")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ur_msgs/cmake" TYPE FILE FILES
    "/home/robot2/catkin_ws/src/cmake-build-debug/universal_robot/ur_msgs/catkin_generated/installspace/ur_msgsConfig.cmake"
    "/home/robot2/catkin_ws/src/cmake-build-debug/universal_robot/ur_msgs/catkin_generated/installspace/ur_msgsConfig-version.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ur_msgs" TYPE FILE FILES "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/package.xml")
endif()


# Install script for directory: /home/robot2/catkin_ws/src/N_Robot

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/N_Robot/srv" TYPE FILE FILES
    "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv"
    "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/N_Robot/cmake" TYPE FILE FILES "/home/robot2/catkin_ws/src/cmake-build-debug/N_Robot/catkin_generated/installspace/N_Robot-msg-paths.cmake")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/robot2/catkin_ws/src/cmake-build-debug/devel/include/N_Robot")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/robot2/catkin_ws/src/cmake-build-debug/devel/share/common-lisp/ros/N_Robot")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/robot2/catkin_ws/src/cmake-build-debug/devel/lib/python2.7/dist-packages/N_Robot")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/robot2/catkin_ws/src/cmake-build-debug/devel/lib/python2.7/dist-packages/N_Robot")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/robot2/catkin_ws/src/cmake-build-debug/N_Robot/catkin_generated/installspace/N_Robot.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/N_Robot/cmake" TYPE FILE FILES "/home/robot2/catkin_ws/src/cmake-build-debug/N_Robot/catkin_generated/installspace/N_Robot-msg-extras.cmake")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/N_Robot/cmake" TYPE FILE FILES
    "/home/robot2/catkin_ws/src/cmake-build-debug/N_Robot/catkin_generated/installspace/N_RobotConfig.cmake"
    "/home/robot2/catkin_ws/src/cmake-build-debug/N_Robot/catkin_generated/installspace/N_RobotConfig-version.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/N_Robot" TYPE FILE FILES "/home/robot2/catkin_ws/src/N_Robot/package.xml")
endif()


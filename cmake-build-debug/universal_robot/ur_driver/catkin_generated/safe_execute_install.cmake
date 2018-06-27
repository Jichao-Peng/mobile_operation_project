execute_process(COMMAND "/home/robot2/catkin_ws/src/cmake-build-debug/universal_robot/ur_driver/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/robot2/catkin_ws/src/cmake-build-debug/universal_robot/ur_driver/catkin_generated/python_distutils_install.sh) returned error code ")
endif()

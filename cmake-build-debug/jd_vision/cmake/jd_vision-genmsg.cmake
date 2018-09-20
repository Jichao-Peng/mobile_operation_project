# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "jd_vision: 3 messages, 0 services")

set(MSG_I_FLAGS "-Ijd_vision:/home/robot2/catkin_ws/src/jd_vision/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Iur_msgs:/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(jd_vision_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/RobotMsg.msg" NAME_WE)
add_custom_target(_jd_vision_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "jd_vision" "/home/robot2/catkin_ws/src/jd_vision/msg/RobotMsg.msg" "ur_msgs/RobotStateRTMsg:std_msgs/Header"
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/Frame.msg" NAME_WE)
add_custom_target(_jd_vision_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "jd_vision" "/home/robot2/catkin_ws/src/jd_vision/msg/Frame.msg" "std_msgs/Header:sensor_msgs/Image"
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/Command.msg" NAME_WE)
add_custom_target(_jd_vision_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "jd_vision" "/home/robot2/catkin_ws/src/jd_vision/msg/Command.msg" "std_msgs/Float32MultiArray:std_msgs/MultiArrayDimension:std_msgs/Header:std_msgs/MultiArrayLayout"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/RobotMsg.msg"
  "${MSG_I_FLAGS}"
  "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/RobotStateRTMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jd_vision
)
_generate_msg_cpp(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/Frame.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jd_vision
)
_generate_msg_cpp(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/Command.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jd_vision
)

### Generating Services

### Generating Module File
_generate_module_cpp(jd_vision
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jd_vision
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(jd_vision_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(jd_vision_generate_messages jd_vision_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/RobotMsg.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_cpp _jd_vision_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/Frame.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_cpp _jd_vision_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/Command.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_cpp _jd_vision_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jd_vision_gencpp)
add_dependencies(jd_vision_gencpp jd_vision_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jd_vision_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/RobotMsg.msg"
  "${MSG_I_FLAGS}"
  "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/RobotStateRTMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jd_vision
)
_generate_msg_lisp(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/Frame.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jd_vision
)
_generate_msg_lisp(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/Command.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jd_vision
)

### Generating Services

### Generating Module File
_generate_module_lisp(jd_vision
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jd_vision
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(jd_vision_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(jd_vision_generate_messages jd_vision_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/RobotMsg.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_lisp _jd_vision_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/Frame.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_lisp _jd_vision_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/Command.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_lisp _jd_vision_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jd_vision_genlisp)
add_dependencies(jd_vision_genlisp jd_vision_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jd_vision_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/RobotMsg.msg"
  "${MSG_I_FLAGS}"
  "/home/robot2/catkin_ws/src/universal_robot/ur_msgs/msg/RobotStateRTMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jd_vision
)
_generate_msg_py(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/Frame.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jd_vision
)
_generate_msg_py(jd_vision
  "/home/robot2/catkin_ws/src/jd_vision/msg/Command.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jd_vision
)

### Generating Services

### Generating Module File
_generate_module_py(jd_vision
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jd_vision
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(jd_vision_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(jd_vision_generate_messages jd_vision_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/RobotMsg.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_py _jd_vision_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/Frame.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_py _jd_vision_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jd_vision/msg/Command.msg" NAME_WE)
add_dependencies(jd_vision_generate_messages_py _jd_vision_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jd_vision_genpy)
add_dependencies(jd_vision_genpy jd_vision_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jd_vision_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jd_vision)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jd_vision
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(jd_vision_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(jd_vision_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET ur_msgs_generate_messages_cpp)
  add_dependencies(jd_vision_generate_messages_cpp ur_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jd_vision)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jd_vision
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(jd_vision_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(jd_vision_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET ur_msgs_generate_messages_lisp)
  add_dependencies(jd_vision_generate_messages_lisp ur_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jd_vision)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jd_vision\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jd_vision
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(jd_vision_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(jd_vision_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET ur_msgs_generate_messages_py)
  add_dependencies(jd_vision_generate_messages_py ur_msgs_generate_messages_py)
endif()

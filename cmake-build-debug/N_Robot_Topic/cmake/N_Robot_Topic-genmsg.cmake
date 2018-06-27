# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "N_Robot_Topic: 7 messages, 0 services")

set(MSG_I_FLAGS "-IN_Robot_Topic:/home/robot2/catkin_ws/src/N_Robot_Topic/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(N_Robot_Topic_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_SetInstantVelocity_msg.msg" NAME_WE)
add_custom_target(_N_Robot_Topic_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot_Topic" "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_SetInstantVelocity_msg.msg" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_EncoderCount_msg.msg" NAME_WE)
add_custom_target(_N_Robot_Topic_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot_Topic" "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_EncoderCount_msg.msg" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_MotionStatus_msg.msg" NAME_WE)
add_custom_target(_N_Robot_Topic_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot_Topic" "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_MotionStatus_msg.msg" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_ClearEncoderCount_msg.msg" NAME_WE)
add_custom_target(_N_Robot_Topic_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot_Topic" "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_ClearEncoderCount_msg.msg" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_BatteryVoltage_msg.msg" NAME_WE)
add_custom_target(_N_Robot_Topic_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot_Topic" "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_BatteryVoltage_msg.msg" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicStatus_msg.msg" NAME_WE)
add_custom_target(_N_Robot_Topic_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot_Topic" "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicStatus_msg.msg" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicData_msg.msg" NAME_WE)
add_custom_target(_N_Robot_Topic_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot_Topic" "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicData_msg.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_SetInstantVelocity_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_cpp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_EncoderCount_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_cpp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_MotionStatus_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_cpp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_ClearEncoderCount_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_cpp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_BatteryVoltage_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_cpp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicStatus_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_cpp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicData_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
)

### Generating Services

### Generating Module File
_generate_module_cpp(N_Robot_Topic
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(N_Robot_Topic_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(N_Robot_Topic_generate_messages N_Robot_Topic_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_SetInstantVelocity_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_cpp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_EncoderCount_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_cpp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_MotionStatus_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_cpp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_ClearEncoderCount_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_cpp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_BatteryVoltage_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_cpp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicStatus_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_cpp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicData_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_cpp _N_Robot_Topic_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(N_Robot_Topic_gencpp)
add_dependencies(N_Robot_Topic_gencpp N_Robot_Topic_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS N_Robot_Topic_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_SetInstantVelocity_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_lisp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_EncoderCount_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_lisp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_MotionStatus_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_lisp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_ClearEncoderCount_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_lisp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_BatteryVoltage_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_lisp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicStatus_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_lisp(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicData_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
)

### Generating Services

### Generating Module File
_generate_module_lisp(N_Robot_Topic
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(N_Robot_Topic_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(N_Robot_Topic_generate_messages N_Robot_Topic_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_SetInstantVelocity_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_lisp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_EncoderCount_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_lisp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_MotionStatus_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_lisp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_ClearEncoderCount_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_lisp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_BatteryVoltage_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_lisp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicStatus_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_lisp _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicData_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_lisp _N_Robot_Topic_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(N_Robot_Topic_genlisp)
add_dependencies(N_Robot_Topic_genlisp N_Robot_Topic_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS N_Robot_Topic_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_SetInstantVelocity_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_py(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_EncoderCount_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_py(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_MotionStatus_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_py(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_ClearEncoderCount_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_py(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_BatteryVoltage_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_py(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicStatus_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
)
_generate_msg_py(N_Robot_Topic
  "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicData_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
)

### Generating Services

### Generating Module File
_generate_module_py(N_Robot_Topic
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(N_Robot_Topic_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(N_Robot_Topic_generate_messages N_Robot_Topic_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_SetInstantVelocity_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_py _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_EncoderCount_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_py _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_MotionStatus_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_py _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_ClearEncoderCount_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_py _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_BatteryVoltage_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_py _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicStatus_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_py _N_Robot_Topic_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot_Topic/msg/NMotionCtrlTopic_UltrasonicData_msg.msg" NAME_WE)
add_dependencies(N_Robot_Topic_generate_messages_py _N_Robot_Topic_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(N_Robot_Topic_genpy)
add_dependencies(N_Robot_Topic_genpy N_Robot_Topic_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS N_Robot_Topic_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot_Topic
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(N_Robot_Topic_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot_Topic
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(N_Robot_Topic_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot_Topic
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(N_Robot_Topic_generate_messages_py std_msgs_generate_messages_py)
endif()

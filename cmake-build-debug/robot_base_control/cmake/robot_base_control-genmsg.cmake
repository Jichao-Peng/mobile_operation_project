# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "robot_base_control: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(robot_base_control_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/robot2/catkin_ws/src/robot_base_control/srv/base_goal.srv" NAME_WE)
add_custom_target(_robot_base_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_base_control" "/home/robot2/catkin_ws/src/robot_base_control/srv/base_goal.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(robot_base_control
  "/home/robot2/catkin_ws/src/robot_base_control/srv/base_goal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_base_control
)

### Generating Module File
_generate_module_cpp(robot_base_control
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_base_control
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(robot_base_control_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(robot_base_control_generate_messages robot_base_control_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/robot_base_control/srv/base_goal.srv" NAME_WE)
add_dependencies(robot_base_control_generate_messages_cpp _robot_base_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_base_control_gencpp)
add_dependencies(robot_base_control_gencpp robot_base_control_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_base_control_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(robot_base_control
  "/home/robot2/catkin_ws/src/robot_base_control/srv/base_goal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_base_control
)

### Generating Module File
_generate_module_lisp(robot_base_control
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_base_control
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(robot_base_control_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(robot_base_control_generate_messages robot_base_control_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/robot_base_control/srv/base_goal.srv" NAME_WE)
add_dependencies(robot_base_control_generate_messages_lisp _robot_base_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_base_control_genlisp)
add_dependencies(robot_base_control_genlisp robot_base_control_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_base_control_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(robot_base_control
  "/home/robot2/catkin_ws/src/robot_base_control/srv/base_goal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_base_control
)

### Generating Module File
_generate_module_py(robot_base_control
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_base_control
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(robot_base_control_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(robot_base_control_generate_messages robot_base_control_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/robot_base_control/srv/base_goal.srv" NAME_WE)
add_dependencies(robot_base_control_generate_messages_py _robot_base_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_base_control_genpy)
add_dependencies(robot_base_control_genpy robot_base_control_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_base_control_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_base_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_base_control
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(robot_base_control_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_base_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_base_control
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(robot_base_control_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_base_control)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_base_control\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_base_control
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(robot_base_control_generate_messages_py std_msgs_generate_messages_py)
endif()

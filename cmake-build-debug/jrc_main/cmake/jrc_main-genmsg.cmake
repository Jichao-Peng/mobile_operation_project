# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "jrc_main: 0 messages, 3 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(jrc_main_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/grasp.srv" NAME_WE)
add_custom_target(_jrc_main_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "jrc_main" "/home/robot2/catkin_ws/src/jrc_main/srv/grasp.srv" "geometry_msgs/Quaternion:std_msgs/String:geometry_msgs/Point:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/agv.srv" NAME_WE)
add_custom_target(_jrc_main_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "jrc_main" "/home/robot2/catkin_ws/src/jrc_main/srv/agv.srv" "std_msgs/String:std_msgs/Bool"
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/input.srv" NAME_WE)
add_custom_target(_jrc_main_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "jrc_main" "/home/robot2/catkin_ws/src/jrc_main/srv/input.srv" "std_msgs/Float64:std_msgs/String"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/grasp.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jrc_main
)
_generate_srv_cpp(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/input.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float64.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jrc_main
)
_generate_srv_cpp(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/agv.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Bool.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jrc_main
)

### Generating Module File
_generate_module_cpp(jrc_main
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jrc_main
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(jrc_main_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(jrc_main_generate_messages jrc_main_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/grasp.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_cpp _jrc_main_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/agv.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_cpp _jrc_main_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/input.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_cpp _jrc_main_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jrc_main_gencpp)
add_dependencies(jrc_main_gencpp jrc_main_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jrc_main_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/grasp.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jrc_main
)
_generate_srv_lisp(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/input.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float64.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jrc_main
)
_generate_srv_lisp(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/agv.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Bool.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jrc_main
)

### Generating Module File
_generate_module_lisp(jrc_main
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jrc_main
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(jrc_main_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(jrc_main_generate_messages jrc_main_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/grasp.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_lisp _jrc_main_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/agv.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_lisp _jrc_main_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/input.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_lisp _jrc_main_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jrc_main_genlisp)
add_dependencies(jrc_main_genlisp jrc_main_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jrc_main_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/grasp.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jrc_main
)
_generate_srv_py(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/input.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float64.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jrc_main
)
_generate_srv_py(jrc_main
  "/home/robot2/catkin_ws/src/jrc_main/srv/agv.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/String.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Bool.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jrc_main
)

### Generating Module File
_generate_module_py(jrc_main
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jrc_main
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(jrc_main_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(jrc_main_generate_messages jrc_main_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/grasp.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_py _jrc_main_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/agv.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_py _jrc_main_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/jrc_main/srv/input.srv" NAME_WE)
add_dependencies(jrc_main_generate_messages_py _jrc_main_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jrc_main_genpy)
add_dependencies(jrc_main_genpy jrc_main_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jrc_main_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jrc_main)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jrc_main
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(jrc_main_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(jrc_main_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jrc_main)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jrc_main
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(jrc_main_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(jrc_main_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jrc_main)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jrc_main\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jrc_main
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(jrc_main_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(jrc_main_generate_messages_py geometry_msgs_generate_messages_py)
endif()

# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "N_Robot: 0 messages, 44 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(N_Robot_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv" ""
)

get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv" NAME_WE)
add_custom_target(_N_Robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "N_Robot" "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)
_generate_srv_cpp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
)

### Generating Module File
_generate_module_cpp(N_Robot
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(N_Robot_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(N_Robot_generate_messages N_Robot_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_cpp _N_Robot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(N_Robot_gencpp)
add_dependencies(N_Robot_gencpp N_Robot_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS N_Robot_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)
_generate_srv_lisp(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
)

### Generating Module File
_generate_module_lisp(N_Robot
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(N_Robot_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(N_Robot_generate_messages N_Robot_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_lisp _N_Robot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(N_Robot_genlisp)
add_dependencies(N_Robot_genlisp N_Robot_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS N_Robot_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)
_generate_srv_py(N_Robot
  "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
)

### Generating Module File
_generate_module_py(N_Robot
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(N_Robot_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(N_Robot_generate_messages N_Robot_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_SetPosition_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadTransData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetSinglePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadEncoder_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JoyCmdMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ResetAllMotorDriver_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetDir_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SMATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ContinueMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/CmdOnly_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_JumpToNextCmd_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_RecoverFactorySet_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_STATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadBatteryVoltage_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SavePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadPosition_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadSinglePara_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StopMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_StartMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_DefineMotorSpeed_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/OFPS1_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATSpeedMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CMATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ClearEncoderCount_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetInstantVelocity_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitTime_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PS_ReadRawData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_WaitForSomeTime_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadMotorVelocity_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadEncoderCount_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadDevInfo_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_CAATPositionMode_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadUltrasonicData_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SuspendMotion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_ReadVersion_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/PBUTTING_ReadStatus_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/robot2/catkin_ws/src/N_Robot/srv/NMotionCtrl_SetOrientation_srv.srv" NAME_WE)
add_dependencies(N_Robot_generate_messages_py _N_Robot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(N_Robot_genpy)
add_dependencies(N_Robot_genpy N_Robot_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS N_Robot_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/N_Robot
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(N_Robot_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/N_Robot
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(N_Robot_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/N_Robot
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(N_Robot_generate_messages_py std_msgs_generate_messages_py)
endif()

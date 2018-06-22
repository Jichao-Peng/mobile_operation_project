#include "Project.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"
#include "stdio.h"
#include "UART.h"
#include "UartNMotion.h"
#include <unistd.h> //sleep()
#include "Algorithm.h"
#include <sys/time.h>
#include <iostream>
#include <string>
#include "N_Robot/NMotionCtrl_ReadDevInfo_srv.h"
#include "N_Robot_Topic/NMotionCtrlTopic_EncoderCount_msg.h"
#include "N_Robot_Topic/NMotionCtrlTopic_MotionStatus_msg.h"
#include "N_Robot_Topic/NMotionCtrlTopic_SetInstantVelocity_msg.h"
#include "N_Robot_Topic/NMotionCtrlTopic_UltrasonicData_msg.h"
#include "N_Robot_Topic/NMotionCtrlTopic_UltrasonicStatus_msg.h"
#include "N_Robot_Topic/NMotionCtrlTopic_BatteryVoltage_msg.h"
#include "N_Robot_Topic/NMotionCtrlTopic_ClearEncoderCount_msg.h"

#include "UserDefine.h"
#include <geometry_msgs/Twist.h>
#include<math.h>
#include<sys/time.h>
#include<iostream>



UartNMotion nMotionUart;
bool g_isCpuLittleEndian;
bool isAbleCommunication=true;
long time_BetweenDataPackage=0;
long time_PublishGeoTwistVelocity=0;//ms
long gTimeCurrentSecWhenOpenDevice=0;

long GetNowTime(void);

//bool ReadDevInfo(N_Robot::NMotionCtrl_ReadDevInfo_srv::Request &req,N_Robot::NMotionCtrl_ReadDevInfo_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[6];
//    ROS_INFO("Service NMotionCtrl/ReadDevInfo is called.");
//    //
//    nErr=nMotionUart.ReadDevInfo(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadDevInfo error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8DevAddr=ac[0];
//    res.u8DevType=ac[1];
//    res.u32DevSN=ac[2]+ac[3]*0x100+ac[4]*0x10000+ac[5]*0x1000000;
//    //**
//    return true;
//}
//bool ReadVersion(N_Robot::NMotionCtrl_ReadVersion_srv::Request &req,N_Robot::NMotionCtrl_ReadVersion_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[6];
//    ROS_INFO("Service NMotionCtrl/ReadVersion is called.");
//    //
//    nErr=nMotionUart.ReadVersion(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadVersion error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u16HrdVer= (float)ac[0]/10+ac[1];
//    res.f32SwVer= (float)ac[2]/1000+(float)ac[3]/100+(float)ac[4]/10+(float)ac[5];
//    //**
//    return true;
//}
//bool Reboot(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[1];
//    ROS_INFO("Service NMotionCtrl/Reboot is called.");
//    //
//    nErr=nMotionUart.Reboot(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr reboot error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    //**
//    return true;
//}
//bool ReadMotionStatus(N_Robot::NMotionCtrl_ReadMotionStatus_srv::Request &req,N_Robot::NMotionCtrl_ReadMotionStatus_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[7];
//    ROS_INFO("Service NMotionCtrl/ReadMotionStatus is called.");
//    //
//    nErr=nMotionUart.ReadMotionStatus(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadMotionStatus error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8MotionStatus=ac[0];
//    res.u8SysErrStatus=ac[1];
//    res.u8MotorErrStatus=ac[2];
//    res.u8MotionBufCnt=ac[3];
//    res.u8CrtMotionBufAddr=ac[4];
//    res.u8CmdBufCnt=ac[5];
//    res.u8CrtCmdBufAddr=ac[6];
//    //**
//    return true;
//}

//bool ResetAllMotorDriver(N_Robot::NMotionCtrl_ResetAllMotorDriver_srv::Request &req,N_Robot::NMotionCtrl_ResetAllMotorDriver_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[1];
//    ROS_INFO("Service NMotionCtrl/ResetAllMotorDriver is called.");
//    //
//    nErr=nMotionUart.ResetAllMotorDriver(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ResetAllMotorDriver error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    //**
//    return true;
//}




//bool ClearMotionBuff(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[1];
//    ROS_INFO("Service NMotionCtrl/ClearMotionBuff is called.");
//    //
//    nErr=nMotionUart.ClearMotionBuff(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ClearMotionBuff error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    //**
//    return true;
//}

//bool ClearErrFlag(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[1];
//    ROS_INFO("Service NMotionCtrl/ClearErrFlag is called.");
//    //
//    nErr=nMotionUart.ClearErrFlag(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ClearErrFlag error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    //**
//    return true;
//}

//bool StartMotion(N_Robot::NMotionCtrl_StartMotion_srv::Request &req,N_Robot::NMotionCtrl_StartMotion_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[1];
//    ROS_INFO("Service NMotionCtrl/StartMotion is called.");
//    //
//    nErr=nMotionUart.StartMotion(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr StartMotion error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8MotionStatus=ac[0];
//    //**
//    return true;
//}

//bool SuspendMotion(N_Robot::NMotionCtrl_SuspendMotion_srv::Request &req,N_Robot::NMotionCtrl_SuspendMotion_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[1];
//    ROS_INFO("Service NMotionCtrl/SuspendMotion is called.");
//    //
//    nErr=nMotionUart.SuspendMotion(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr SuspendMotion error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8MotionStatus=ac[0];
//    //**
//    return true;
//}

//bool ContinueMotion(N_Robot::NMotionCtrl_ContinueMotion_srv::Request &req,N_Robot::NMotionCtrl_ContinueMotion_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[1];
//    ROS_INFO("Service NMotionCtrl/ContinueMotion is called.");
//    //
//    nErr=nMotionUart.ContinueMotion(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ContinueMotion error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8MotionStatus=ac[0];
//    //**
//    return true;
//}

//bool StopMotion(N_Robot::NMotionCtrl_StopMotion_srv::Request &req,N_Robot::NMotionCtrl_StopMotion_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[2];
//    ROS_INFO("Service NMotionCtrl/StopMotion is called.");
//    //
//    nErr=nMotionUart.StopMotion(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr StopMotion error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8MotionStatus=ac[0];
//    res.u8SysErrStatus=ac[1];
//    //**
//    return true;
//}

//bool JumpToNextCmd(N_Robot::NMotionCtrl_JumpToNextCmd_srv::Request &req,N_Robot::NMotionCtrl_JumpToNextCmd_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[2];
//    ROS_INFO("Service NMotionCtrl/JumpToNextCmd is called.");
//    //
//    nErr=nMotionUart.JumpToNextCmd(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr JumpToNextCmd error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8MotionStatus=ac[0];
//    res.u8SysErrStatus=ac[1];
//    //**
//    return true;
//}

//bool StopMotionAndSetDir(N_Robot::NMotionCtrl_SetDir_srv::Request &req,N_Robot::NMotionCtrl_SetDir_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[4];
//    ROS_INFO("Service NMotionCtrl/StopMotionAndSetDir is called.");
//    //
//    Union64 union64;

//    union64.f32[0]=req.f32Direction;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    ac[2]=union64.u8[2];
//    ac[3]=union64.u8[3];
//    //
//    nErr=nMotionUart.StopMotionAndSetDir(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr StopMotionAndSetDir error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    if(res.u8SysErrStatus!=0){
//        res.s32ErrCode=5;
//        res.strErrInfo="The angel to set is out of range!";
//    }
//    //**
//    return true;
//}
//bool SetDirAfterMotion(N_Robot::NMotionCtrl_SetDir_srv::Request &req,N_Robot::NMotionCtrl_SetDir_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[4];
//    ROS_INFO("Service NMotionCtrl/SetDirAfterMotion is called.");
//    //
//    Union64 union64;

//    union64.f32[0]=req.f32Direction;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    ac[2]=union64.u8[2];
//    ac[3]=union64.u8[3];
//    //
//    nErr=nMotionUart.SetDirAfterMotion(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr SetDirAfterMotion error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    if(res.u8SysErrStatus!=0){
//        res.s32ErrCode=5;
//        res.strErrInfo="The angel to set is out of range!";
//    }
//    //**
//    return true;
//}
//bool WaitTime(N_Robot::NMotionCtrl_WaitTime_srv::Request &req,N_Robot::NMotionCtrl_WaitTime_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[2];
//    ROS_INFO("Service NMotionCtrl/WaitTime is called.");
//    //
//    Union64 union64;

//    union64.u16[0]=req.u16Time;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];

//    //
//    nErr=nMotionUart.WaitTime(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr WaitTime error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}

//bool SetInstantVelocity(N_Robot::NMotionCtrl_SetInstantVelocity_srv::Request &req,N_Robot::NMotionCtrl_SetInstantVelocity_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[6];
//    ROS_INFO("Service NMotionCtrl/SetInstantVelocity is called.req:direction angle:%d,linearVel:%d,AngularVel:%d",
//             req.s16DirectionAngle,req.u16LinearVelocity,req.s16AngularVelocity);
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16DirectionAngle;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.u16[0]=req.u16LinearVelocity;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.s16[0]=req.s16AngularVelocity;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    //
//    nErr=nMotionUart.SetInstantVelocity(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr SetInstantVelocity error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}
//bool SMATSpeedMode(N_Robot::NMotionCtrl_SMATSpeedMode_srv::Request &req,N_Robot::NMotionCtrl_SMATSpeedMode_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[6];
//    ROS_INFO("Service NMotionCtrl/SMATSpeedMode is called.req:direction angle:%d,linearVel:%d,AngularVel:%d",
//             req.s16DirectionAngle,req.u16LinearVelocity,req.s16AngularVelocity);
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16DirectionAngle;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.u16[0]=req.u16LinearVelocity;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.s16[0]=req.s16AngularVelocity;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    //
//    nErr=nMotionUart.SMATSpeedMode(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr SMATSpeedMode error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}
//bool CMATSpeedMode(N_Robot::NMotionCtrl_CMATSpeedMode_srv::Request &req,N_Robot::NMotionCtrl_CMATSpeedMode_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[8];
//    ROS_INFO("Service NMotionCtrl/CMATSpeedMode is called.");
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16DirectionAngle;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.u16[0]=req.u16CycleR;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.u16[0]=req.u16LinearVelocity;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    union64.s16[0]=req.s16AngularVelocity;
//    ac[6]=union64.u8[0];
//    ac[7]=union64.u8[1];
//    //
//    nErr=nMotionUart.CMATSpeedMode(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr CMATSpeedMode error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}
//bool CAATSpeedMode(N_Robot::NMotionCtrl_CMATSpeedMode_srv::Request &req,N_Robot::NMotionCtrl_CMATSpeedMode_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[8];
//    ROS_INFO("Service NMotionCtrl/CAATSpeedMode is called.");
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16DirectionAngle;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.u16[0]=req.u16CycleR;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.u16[0]=req.u16LinearVelocity;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    union64.s16[0]=req.s16AngularVelocity;
//    ac[6]=union64.u8[0];
//    ac[7]=union64.u8[1];
//    //
//    nErr=nMotionUart.CAATSpeedMode(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr CAATSpeedMode error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}
//bool DefineMotorSpeed(N_Robot::NMotionCtrl_DefineMotorSpeed_srv::Request &req,N_Robot::NMotionCtrl_DefineMotorSpeed_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[6];
//    ROS_INFO("Service NMotionCtrl/DefineMotorSpeed is called.req:Wheel1:%d,Wheel2:%d,Wheel3:%d,Wheel4:%d",
//             req.s16Wheel1,req.s16Wheel2,req.s16Wheel3,req.s16Wheel4);
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16Wheel1;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.s16[0]=req.s16Wheel2;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.s16[0]=req.s16Wheel3;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    union64.s16[0]=req.s16Wheel4;
//    ac[6]=union64.u8[0];
//    ac[7]=union64.u8[1];
//    //
//    nErr=nMotionUart.DefineMotorSpeed(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr DefineMotorSpeed error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}

//bool SMATPositionMode(N_Robot::NMotionCtrl_SMATPositionMode_srv::Request &req,N_Robot::NMotionCtrl_SMATPositionMode_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[8];
//    ROS_INFO("Service NMotionCtrl/SMATPositionMode is called.");
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16X;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.s16[0]=req.s16Y;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.u16[0]=req.u16LinearVelocity;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    union64.s16[0]=req.s16AngularVelocity;
//    ac[6]=union64.u8[0];
//    ac[7]=union64.u8[1];
//    //
//    nErr=nMotionUart.SMATPositionMode(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr SMATPositionMode error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}

//bool STATPositionMode(N_Robot::NMotionCtrl_STATPositionMode_srv::Request &req,N_Robot::NMotionCtrl_STATPositionMode_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[8];
//    ROS_INFO("Service NMotionCtrl/STATPositionMode is called.");
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16DirectionAngle;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.s16[0]=req.s16Distance;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.u16[0]=req.u16LinearVelocity;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    union64.s16[0]=req.s16AngularVelocity;
//    ac[6]=union64.u8[0];
//    ac[7]=union64.u8[1];
//    //
//    nErr=nMotionUart.STATPositionMode(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr STATPositionMode error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}

//bool CMATPositionMode(N_Robot::NMotionCtrl_CMATPositionMode_srv::Request &req,N_Robot::NMotionCtrl_CMATPositionMode_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[10];
//    ROS_INFO("Service NMotionCtrl/CMATPositionMode is called.");
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16X;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.s16[0]=req.s16Y;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.u16[0]=req.u16CycleR;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    union64.u16[0]=req.u16LinearVelocity;
//    ac[6]=union64.u8[0];
//    ac[7]=union64.u8[1];
//    union64.s16[0]=req.s16AngularVelocity;
//    ac[8]=union64.u8[0];
//    ac[9]=union64.u8[1];
//    //
//    nErr=nMotionUart.CMATPositionMode(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr CMATPositionMode error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}

//bool CAATPositionMode(N_Robot::NMotionCtrl_CAATPositionMode_srv::Request &req,N_Robot::NMotionCtrl_CAATPositionMode_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[10];
//    ROS_INFO("Service NMotionCtrl/CAATPositionMode is called.");
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16X;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.s16[0]=req.s16Y;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.u16[0]=req.u16CycleR;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    union64.u16[0]=req.u16LinearVelocity;
//    ac[6]=union64.u8[0];
//    ac[7]=union64.u8[1];
//    union64.s16[0]=req.s16AngularVelocity;
//    ac[8]=union64.u8[0];
//    ac[9]=union64.u8[1];
//    //
//    nErr=nMotionUart.CAATPositionMode(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr CAATPositionMode error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}
//bool JoyCmdMotion(N_Robot::NMotionCtrl_JoyCmdMotion_srv::Request &req,N_Robot::NMotionCtrl_JoyCmdMotion_srv::Response &res){
//    int nErr;
//    string strErr;
//    //**
//    unsigned char ac[6];
//    ROS_INFO("Service NMotionCtrl/JoyCmdMotion is called.req:Joy X:%d,Joy Y:%d,Joy Z:%d",
//             req.s16JoyX,req.s16JoyY,req.s16JoyZ);
//    //
//    Union64 union64;

//    union64.s16[0]=req.s16JoyX;
//    ac[0]=union64.u8[0];
//    ac[1]=union64.u8[1];
//    union64.s16[0]=req.s16JoyY;
//    ac[2]=union64.u8[0];
//    ac[3]=union64.u8[1];
//    union64.s16[0]=req.s16JoyZ;
//    ac[4]=union64.u8[0];
//    ac[5]=union64.u8[1];
//    //
//    nErr=nMotionUart.JoyCmdMotion(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr JoyCmdMotion error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    //**
//    return true;
//}


//bool SavePara(N_Robot::NMotionCtrl_SavePara_srv::Request &req,N_Robot::NMotionCtrl_ResetAllMotorDriver_srv::Response &res){
//    int nErr;
//    string strErr;
//    unsigned char ac[1];

//    ROS_INFO("Service NMotionCtrl/SavePara is called.");
//    nErr=nMotionUart.SavePara(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr SavePara error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    return true;
//}

//bool RecoverFactorySet(N_Robot::NMotionCtrl_RecoverFactorySet_srv::Request &req,N_Robot::NMotionCtrl_RecoverFactorySet_srv::Response &res){
//    unsigned char ac[1];

//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/RecoverFactorySet is called.");
//    nErr=nMotionUart.RecoverFactorySet(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr RecoverFactorySet error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    return true;
//}

//bool ReadSinglePara(N_Robot::NMotionCtrl_ReadSinglePara_srv::Request &req,N_Robot::NMotionCtrl_ReadSinglePara_srv::Response &res){
//    unsigned char ac[5];
//    ac[0]=req.paraIndex;

//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/ReadSinglePara is called.");
//    nErr=nMotionUart.ReadSinglePara(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadSinglePara error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.paraIndex=ac[0];
//    res.paraData1=ac[1];
//    res.paraData2=ac[2];
//    res.paraData3=ac[3];
//    res.paraData4=ac[4];
//    return true;
//}
//bool SetSinglePara(N_Robot::NMotionCtrl_SetSinglePara_srv::Request &req,N_Robot::NMotionCtrl_SetSinglePara_srv::Response &res){
//    unsigned char ac[5];
//    ac[0]=req.paraIndex;
//    ac[1]=req.paraData1;
//    ac[2]=req.paraData2;
//    ac[3]=req.paraData3;
//    ac[4]=req.paraData3;

//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/SetSinglePara is called.");
//    nErr=nMotionUart.SetSinglePara(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr SetSinglePara error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    return true;
//}

//bool SetOrientation(N_Robot::NMotionCtrl_SetOrientation_srv::Request &req,N_Robot::NMotionCtrl_SetOrientation_srv::Response &res){
//    unsigned char ac[4];
//    Union32 tempUnion32;
//    tempUnion32.f32=req.orientation;
//    if(g_isCpuLittleEndian){
//        ac[0]=tempUnion32.u8[0];
//        ac[1]=tempUnion32.u8[1];
//        ac[2]=tempUnion32.u8[2];
//        ac[3]=tempUnion32.u8[3];
//    }else{
//        ac[0]=tempUnion32.u8[3];
//        ac[1]=tempUnion32.u8[2];
//        ac[2]=tempUnion32.u8[1];
//        ac[3]=tempUnion32.u8[0];
//    }

//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/SetOrientation is called.");
//    nErr=nMotionUart.SetOrientation(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr SetOrientation error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    return true;
//}
//bool WaitForSomeTime(N_Robot::NMotionCtrl_WaitForSomeTime_srv::Request &req,N_Robot::NMotionCtrl_WaitForSomeTime_srv::Response &res){
//    unsigned char ac[2];
//    Union16 tempUnion16;
//    tempUnion16.u16=req.timeForWait;
//    if(g_isCpuLittleEndian){
//        ac[0]=tempUnion16.u8[0];
//        ac[1]=tempUnion16.u8[1];
//    }else{
//        ac[0]=tempUnion16.u8[3];
//        ac[1]=tempUnion16.u8[2];
//    }

//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/WaitForSomeTime is called.");
//    nErr=nMotionUart.WaitForSomeTime(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr WaitForSomeTime error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    return true;
//}

//bool CAATSpeedMode_(N_Robot::NMotionCtrl_CAATSpeedMode_srv::Request &req,N_Robot::NMotionCtrl_CAATSpeedMode_srv::Response &res){
//    unsigned char ac[8];
//    Union16 tempUnion16a,tempUnion16b,tempUnion16c,tempUnion16d;
//    tempUnion16a.s16=req.s16DirectionAngle;
//    tempUnion16a.u16=req.u16CycleR;
//    tempUnion16a.u16=req.u16LinearVelocity;
//    tempUnion16a.s16=req.s16AngularVelocity;

//    if(g_isCpuLittleEndian){
//        ac[0]=tempUnion16a.u8[0];
//        ac[1]=tempUnion16a.u8[1];
//        ac[2]=tempUnion16b.u8[0];
//        ac[3]=tempUnion16b.u8[1];
//        ac[4]=tempUnion16c.u8[0];
//        ac[5]=tempUnion16c.u8[1];
//        ac[6]=tempUnion16d.u8[0];
//        ac[7]=tempUnion16d.u8[1];
//    }else{
//        ac[1]=tempUnion16a.u8[0];
//        ac[0]=tempUnion16a.u8[1];
//        ac[3]=tempUnion16b.u8[0];
//        ac[2]=tempUnion16b.u8[1];
//        ac[5]=tempUnion16c.u8[0];
//        ac[4]=tempUnion16c.u8[1];
//        ac[7]=tempUnion16d.u8[0];
//        ac[6]=tempUnion16d.u8[1];
//    }

//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/CAATSpeedMode is called.");
//    nErr=nMotionUart.CAATSpeedMode(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr CAATSpeedMode error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.u8SysErrStatus=ac[0];
//    return true;
//}

//bool ReadBatteryVoltage(N_Robot::NMotionCtrl_ReadBatteryVoltage_srv::Request &req,N_Robot::NMotionCtrl_ReadBatteryVoltage_srv::Response &res){
//    unsigned char ac[2];
//    Union16 tempUnion16;
//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/ReadBatteryVoltage is called.");
//    nErr=nMotionUart.ReadBatteryVoltage(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadBatteryVoltage error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    if(g_isCpuLittleEndian){
//        tempUnion16.u8[0]=ac[0];
//        tempUnion16.u8[1]=ac[1];
//    }else{
//        tempUnion16.u8[1]=ac[0];
//        tempUnion16.u8[0]=ac[1];
//    }
//    res.batteryVoltage=((float_t)tempUnion16.u16)/10;
//    return true;
//}

//bool ReadUltrasonicData(N_Robot::NMotionCtrl_ReadUltrasonicData_srv::Request &req,N_Robot::NMotionCtrl_ReadUltrasonicData_srv::Response &res){
//    unsigned char ac[12];

//    Union16 tempUnion16_1,tempUnion16_2,tempUnion16_3,tempUnion16_4,tempUnion16_5,tempUnion16_6;
//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/ReadUltrasonicData is called.");
//    nErr=nMotionUart.ReadUltrasonicData(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadUltrasonicData error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    if(g_isCpuLittleEndian){
//        tempUnion16_1.u8[0]=ac[0];
//        tempUnion16_1.u8[1]=ac[1];
//        tempUnion16_2.u8[0]=ac[2];
//        tempUnion16_2.u8[1]=ac[3];
//        tempUnion16_3.u8[0]=ac[4];
//        tempUnion16_3.u8[1]=ac[5];
//        tempUnion16_4.u8[0]=ac[6];
//        tempUnion16_4.u8[1]=ac[7];
//        tempUnion16_5.u8[0]=ac[8];
//        tempUnion16_5.u8[1]=ac[9];
//        tempUnion16_6.u8[0]=ac[10];
//        tempUnion16_6.u8[1]=ac[11];
//    }else{
//        tempUnion16_1.u8[1]=ac[0];
//        tempUnion16_1.u8[0]=ac[1];
//        tempUnion16_2.u8[1]=ac[2];
//        tempUnion16_2.u8[0]=ac[3];
//        tempUnion16_3.u8[1]=ac[4];
//        tempUnion16_3.u8[0]=ac[5];
//        tempUnion16_4.u8[1]=ac[6];
//        tempUnion16_4.u8[0]=ac[7];
//        tempUnion16_5.u8[1]=ac[8];
//        tempUnion16_5.u8[0]=ac[9];
//        tempUnion16_6.u8[1]=ac[10];
//        tempUnion16_6.u8[0]=ac[11];
//    }
//    res.ultrasonic1Data=tempUnion16_1.u16;
//    res.ultrasonic2Data=tempUnion16_2.u16;
//    res.ultrasonic3Data=tempUnion16_3.u16;
//    res.ultrasonic4Data=tempUnion16_4.u16;
//    res.ultrasonic5Data=tempUnion16_5.u16;
//    res.ultrasonic6Data=tempUnion16_6.u16;
//    return true;
//}
//bool ReadUltrasonicStatus(N_Robot::NMotionCtrl_ReadUltrasonicStatus_srv::Request &req,N_Robot::NMotionCtrl_ReadUltrasonicStatus_srv::Response &res){
//    unsigned char ac[1];

//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/ReadUltrasonicStatus is called.");
//    nErr=nMotionUart.ReadUltrasonicStatus(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadUltrasonicStatus error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    res.ultrasonic1Status=  ((ac[0]>>0)&0x01);
//    res.ultrasonic2Status=  ((ac[0]>>1)&0x01);
//    res.ultrasonic3Status=  ((ac[0]>>2)&0x01);
//    res.ultrasonic4Status=  ((ac[0]>>3)&0x01);
//    res.ultrasonic5Status=  ((ac[0]>>4)&0x01);
//    res.ultrasonic6Status=  ((ac[0]>>5)&0x01);
//    return true;
//}
//bool ReadMotorVelocity(N_Robot::NMotionCtrl_ReadMotorVelocity_srv::Request &req,N_Robot::NMotionCtrl_ReadMotorVelocity_srv::Response &res){
//    unsigned char ac[16];
//    Union32 tempUnion32_1,tempUnion32_2,tempUnion32_3,tempUnion32_4;
//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/ReadMotorVelocity is called.");
//    nErr=nMotionUart.ReadMotorVelocity(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadMotorVelocity error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    if(g_isCpuLittleEndian){
//        tempUnion32_1.u8[0]=ac[0];
//        tempUnion32_1.u8[1]=ac[1];
//        tempUnion32_1.u8[2]=ac[2];
//        tempUnion32_1.u8[3]=ac[3];
//        tempUnion32_2.u8[0]=ac[4];
//        tempUnion32_2.u8[1]=ac[5];
//        tempUnion32_2.u8[2]=ac[6];
//        tempUnion32_2.u8[3]=ac[7];
//        tempUnion32_3.u8[0]=ac[8];
//        tempUnion32_3.u8[1]=ac[9];
//        tempUnion32_3.u8[2]=ac[10];
//        tempUnion32_3.u8[3]=ac[11];
//        tempUnion32_4.u8[0]=ac[12];
//        tempUnion32_4.u8[1]=ac[13];
//        tempUnion32_4.u8[2]=ac[14];
//        tempUnion32_4.u8[3]=ac[15];
//    }else{
//        tempUnion32_1.u8[3]=ac[0];
//        tempUnion32_1.u8[2]=ac[1];
//        tempUnion32_1.u8[1]=ac[2];
//        tempUnion32_1.u8[0]=ac[3];
//        tempUnion32_2.u8[3]=ac[4];
//        tempUnion32_2.u8[2]=ac[5];
//        tempUnion32_2.u8[1]=ac[6];
//        tempUnion32_2.u8[0]=ac[7];
//        tempUnion32_3.u8[3]=ac[8];
//        tempUnion32_3.u8[2]=ac[9];
//        tempUnion32_3.u8[1]=ac[10];
//        tempUnion32_3.u8[0]=ac[11];
//        tempUnion32_4.u8[3]=ac[12];
//        tempUnion32_4.u8[2]=ac[13];
//        tempUnion32_4.u8[1]=ac[14];
//        tempUnion32_4.u8[0]=ac[15];
//    }
//    res.motor1Velocity=tempUnion32_1.i32;
//    res.motor2Velocity=tempUnion32_2.i32;
//    res.motor3Velocity=tempUnion32_3.i32;
//    res.motor4Velocity=tempUnion32_4.i32;
//    return true;
//}
//bool ReadEncoderCount(N_Robot::NMotionCtrl_ReadEncoderCount_srv::Request &req,N_Robot::NMotionCtrl_ReadEncoderCount_srv::Response &res){
//    unsigned char ac[16];
//    Union32 tempUnion32_1,tempUnion32_2,tempUnion32_3,tempUnion32_4;
//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/ReadEncoderCount is called.");
//    nErr=nMotionUart.ReadEncoderCount(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ReadEncoderCount error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;
//    if(g_isCpuLittleEndian){
//        tempUnion32_1.u8[0]=ac[0];
//        tempUnion32_1.u8[1]=ac[1];
//        tempUnion32_1.u8[2]=ac[2];
//        tempUnion32_1.u8[3]=ac[3];
//        tempUnion32_2.u8[0]=ac[4];
//        tempUnion32_2.u8[1]=ac[5];
//        tempUnion32_2.u8[2]=ac[6];
//        tempUnion32_2.u8[3]=ac[7];
//        tempUnion32_3.u8[0]=ac[8];
//        tempUnion32_3.u8[1]=ac[9];
//        tempUnion32_3.u8[2]=ac[10];
//        tempUnion32_3.u8[3]=ac[11];
//        tempUnion32_4.u8[0]=ac[12];
//        tempUnion32_4.u8[1]=ac[13];
//        tempUnion32_4.u8[2]=ac[14];
//        tempUnion32_4.u8[3]=ac[15];
//    }else{
//        tempUnion32_1.u8[3]=ac[0];
//        tempUnion32_1.u8[2]=ac[1];
//        tempUnion32_1.u8[1]=ac[2];
//        tempUnion32_1.u8[0]=ac[3];
//        tempUnion32_2.u8[3]=ac[4];
//        tempUnion32_2.u8[2]=ac[5];
//        tempUnion32_2.u8[1]=ac[6];
//        tempUnion32_2.u8[0]=ac[7];
//        tempUnion32_3.u8[3]=ac[8];
//        tempUnion32_3.u8[2]=ac[9];
//        tempUnion32_3.u8[1]=ac[10];
//        tempUnion32_3.u8[0]=ac[11];
//        tempUnion32_4.u8[3]=ac[12];
//        tempUnion32_4.u8[2]=ac[13];
//        tempUnion32_4.u8[1]=ac[14];
//        tempUnion32_4.u8[0]=ac[15];
//    }
//    res.encoder1Count=tempUnion32_1.i32;
//    res.encoder2Count=tempUnion32_2.i32;
//    res.encoder3Count=tempUnion32_3.i32;
//    res.encoder4Count=tempUnion32_4.i32;
//    return true;
//}
//bool ClearEncoderCount(N_Robot::NMotionCtrl_ClearEncoderCount_srv::Request &req,N_Robot::NMotionCtrl_ClearEncoderCount_srv::Response &res){
//    unsigned char ac[1];

//    int nErr;
//    string strErr;
//    ROS_INFO("Service NMotionCtrl/ClearEncoderCount is called.");
//    nErr=nMotionUart.ClearEncoderCount(ac,strErr);
//    if(nErr){
//        cout<<"NMotionSvr ClearEncoderCount error:"<<strErr<<"\n";
//    }
//    res.s32ErrCode=nErr;
//    res.strErrInfo=strErr;

//    return true;
//}

void FucReadMotionStatus(unsigned char* ac,string &strErr,ros::Publisher &msgPub,N_Robot_Topic::NMotionCtrlTopic_MotionStatus_msg &msg){
    if(nMotionUart.ReadMotionStatus(ac,strErr)==0){//true
        msg.isCommunicationOK=true;
        msg.u8MotionStatus=ac[0];
        msg.u8SysErrStatus=ac[1];
        msg.u8MotorErrStatus=ac[2];
        msg.u8MotionBufCnt=ac[3];
        msg.u8CrtMotionBufAddr=ac[4];
        msg.u8CmdBufCnt=ac[5];
        msg.u8CrtCmdBufAddr=ac[6];
    }else{//false
        msg.isCommunicationOK=false;
        msg.u8MotionStatus=0;
        msg.u8SysErrStatus=0;
        msg.u8MotorErrStatus=0;
        msg.u8MotionBufCnt=0;
        msg.u8CrtMotionBufAddr=0;
        msg.u8CmdBufCnt=0;
        msg.u8CrtCmdBufAddr=0;
        cout<<strErr<<endl;
    }
    msgPub.publish(msg);
    return ;
}

void FucReadUltrasonicData(unsigned char* ac,string &strErr,ros::Publisher &msgPub,N_Robot_Topic::NMotionCtrlTopic_UltrasonicData_msg &msg){
    if(nMotionUart.ReadUltrasonicData(ac,strErr)==0){//true
        msg.isCommunicationOK=true;
        Union16 tempUnion16_1,tempUnion16_2,tempUnion16_3,tempUnion16_4,tempUnion16_5,tempUnion16_6;
        if(g_isCpuLittleEndian){
            tempUnion16_1.u8[0]=ac[0];
            tempUnion16_1.u8[1]=ac[1];
            tempUnion16_2.u8[0]=ac[2];
            tempUnion16_2.u8[1]=ac[3];
            tempUnion16_3.u8[0]=ac[4];
            tempUnion16_3.u8[1]=ac[5];
            tempUnion16_4.u8[0]=ac[6];
            tempUnion16_4.u8[1]=ac[7];
            tempUnion16_5.u8[0]=ac[8];
            tempUnion16_5.u8[1]=ac[9];
            tempUnion16_6.u8[0]=ac[10];
            tempUnion16_6.u8[1]=ac[11];
        }else{
            tempUnion16_1.u8[1]=ac[0];
            tempUnion16_1.u8[0]=ac[1];
            tempUnion16_2.u8[1]=ac[2];
            tempUnion16_2.u8[0]=ac[3];
            tempUnion16_3.u8[1]=ac[4];
            tempUnion16_3.u8[0]=ac[5];
            tempUnion16_4.u8[1]=ac[6];
            tempUnion16_4.u8[0]=ac[7];
            tempUnion16_5.u8[1]=ac[8];
            tempUnion16_5.u8[0]=ac[9];
            tempUnion16_6.u8[1]=ac[10];
            tempUnion16_6.u8[0]=ac[11];
        }
        msg.ultrasonic1Data=(u_int16_t)(((float)tempUnion16_1.u16)/5.8);
        msg.ultrasonic2Data=(u_int16_t)(((float)tempUnion16_2.u16)/5.8);
        msg.ultrasonic3Data=(u_int16_t)(((float)tempUnion16_3.u16)/5.8);
        msg.ultrasonic4Data=(u_int16_t)(((float)tempUnion16_4.u16)/5.8);
        msg.ultrasonic5Data=(u_int16_t)(((float)tempUnion16_5.u16)/5.8);
        msg.ultrasonic6Data=(u_int16_t)(((float)tempUnion16_6.u16)/5.8);
    }else{//false
        msg.isCommunicationOK=false;
        msg.ultrasonic1Data=0;
        msg.ultrasonic2Data=0;
        msg.ultrasonic3Data=0;
        msg.ultrasonic4Data=0;
        msg.ultrasonic5Data=0;
        msg.ultrasonic6Data=0;
    }
    msgPub.publish(msg);
    return ;
}

void FucReadUltrasonicStatus(unsigned char* ac,string &strErr,ros::Publisher &msgPub,N_Robot_Topic::NMotionCtrlTopic_UltrasonicStatus_msg &msg){
    if(nMotionUart.ReadUltrasonicStatus(ac,strErr)==0){//true
        msg.isCommunicationOK=true;
        msg.ultrasonic1Status=  ((ac[0]>>0)&0x01);
        msg.ultrasonic2Status=  ((ac[0]>>1)&0x01);
        msg.ultrasonic3Status=  ((ac[0]>>2)&0x01);
        msg.ultrasonic4Status=  ((ac[0]>>3)&0x01);
        msg.ultrasonic5Status=  ((ac[0]>>4)&0x01);
        msg.ultrasonic6Status=  ((ac[0]>>5)&0x01);
    }else{//false
        msg.isCommunicationOK=false;
        msg.ultrasonic1Status=0;
        msg.ultrasonic2Status=0;
        msg.ultrasonic3Status=0;
        msg.ultrasonic4Status=0;
        msg.ultrasonic5Status=0;
        msg.ultrasonic6Status=0;
    }
    msgPub.publish(msg);
    return ;
}

void FucReadBatteryVoltage(unsigned char* ac,string &strErr,ros::Publisher &msgPub,N_Robot_Topic::NMotionCtrlTopic_BatteryVoltage_msg &msg){
    Union16 tempUnion16;
    if(nMotionUart.ReadBatteryVoltage(ac,strErr)==0){//true
        msg.isCommunicationOK=true;
        if(g_isCpuLittleEndian){
            tempUnion16.u8[0]=ac[0];
            tempUnion16.u8[1]=ac[1];
        }else{
            tempUnion16.u8[1]=ac[0];
            tempUnion16.u8[0]=ac[1];
        }
        msg.batteryVoltage=((float_t)tempUnion16.u16)/10;
    }else{//false
        msg.isCommunicationOK=false;
        msg.batteryVoltage=48;
    }
    msgPub.publish(msg);
    return ;
}

void FucReadEncoderCount(unsigned char* ac,string &strErr,ros::Publisher &msgPub,N_Robot_Topic::NMotionCtrlTopic_EncoderCount_msg &msg){
    if(nMotionUart.ReadEncoderCount(ac,strErr)==0){//true
        msg.isCommunicationOK=true;
        Union32 tempUnion32_1,tempUnion32_2,tempUnion32_3,tempUnion32_4;
        if(g_isCpuLittleEndian){
            tempUnion32_1.u8[0]=ac[0];
            tempUnion32_1.u8[1]=ac[1];
            tempUnion32_1.u8[2]=ac[2];
            tempUnion32_1.u8[3]=ac[3];
            tempUnion32_2.u8[0]=ac[4];
            tempUnion32_2.u8[1]=ac[5];
            tempUnion32_2.u8[2]=ac[6];
            tempUnion32_2.u8[3]=ac[7];
            tempUnion32_3.u8[0]=ac[8];
            tempUnion32_3.u8[1]=ac[9];
            tempUnion32_3.u8[2]=ac[10];
            tempUnion32_3.u8[3]=ac[11];
            tempUnion32_4.u8[0]=ac[12];
            tempUnion32_4.u8[1]=ac[13];
            tempUnion32_4.u8[2]=ac[14];
            tempUnion32_4.u8[3]=ac[15];
        }else{
            tempUnion32_1.u8[3]=ac[0];
            tempUnion32_1.u8[2]=ac[1];
            tempUnion32_1.u8[1]=ac[2];
            tempUnion32_1.u8[0]=ac[3];
            tempUnion32_2.u8[3]=ac[4];
            tempUnion32_2.u8[2]=ac[5];
            tempUnion32_2.u8[1]=ac[6];
            tempUnion32_2.u8[0]=ac[7];
            tempUnion32_3.u8[3]=ac[8];
            tempUnion32_3.u8[2]=ac[9];
            tempUnion32_3.u8[1]=ac[10];
            tempUnion32_3.u8[0]=ac[11];
            tempUnion32_4.u8[3]=ac[12];
            tempUnion32_4.u8[2]=ac[13];
            tempUnion32_4.u8[1]=ac[14];
            tempUnion32_4.u8[0]=ac[15];
        }
        msg.encoder1Count=tempUnion32_1.i32;
        msg.encoder2Count=tempUnion32_2.i32;
        msg.encoder3Count=tempUnion32_3.i32;
        msg.encoder4Count=tempUnion32_4.i32;
    }else{//false
        msg.isCommunicationOK=false;
        msg.encoder1Count=0;
        msg.encoder2Count=0;
        msg.encoder3Count=0;
        msg.encoder4Count=0;
        cout<<strErr<<endl;
    }
    msgPub.publish(msg);
    return ;
}

void SetInstantVelocityCallback(const N_Robot_Topic::NMotionCtrlTopic_SetInstantVelocity_msg::ConstPtr& msg){
    Union16 union16;
    unsigned char ac[50];
    string strErr;
    if(g_isCpuLittleEndian){
        union16.s16=msg->s16DirectionAngle;
        ac[0]=union16.u8[0];
        ac[1]=union16.u8[1];
        union16.u16=msg->u16LinearVelocity;
        ac[2]=union16.u8[0];
        ac[3]=union16.u8[1];
        union16.s16=msg->s16AngularVelocity;
        ac[4]=union16.u8[0];
        ac[5]=union16.u8[1];
    }else{
        union16.s16=msg->s16DirectionAngle;
        ac[0]=union16.u8[1];
        ac[1]=union16.u8[0];
        union16.u16=msg->u16LinearVelocity;
        ac[2]=union16.u8[1];
        ac[3]=union16.u8[0];
        union16.s16=msg->s16AngularVelocity;
        ac[4]=union16.u8[1];
        ac[5]=union16.u8[0];
    }
    if(nMotionUart.SetInstantVelocity(ac,strErr)==0){
       // ROS_INFO("set the velocity..");
    }else{
        ROS_ERROR("Can't set the velocity!Maybe the conmmunication is not OK!");
    }
}

void GeoTwistSetInstantVelocityCallback(const geometry_msgs::Twist::ConstPtr& msgPrimary){
    Union16 union16;
    unsigned char ac[50];
    string strErr;
    int16_t s16DirectionAngle;
    u_int16_t u16LinearVelocity;
    int16_t s16AngularVelocity;

    isAbleCommunication=false;

   // ROS_INFO("the vec is %f",msgPrimary->angular.z);
    geometry_msgs::Twist* msg=new geometry_msgs::Twist;
    msg->linear.x=msgPrimary->linear.x;
    msg->linear.y=msgPrimary->linear.y*(-1);
    msg->linear.z=msgPrimary->linear.z;
    msg->angular.x=msgPrimary->angular.x;
    msg->angular.y=msgPrimary->angular.y;
    msg->angular.z=msgPrimary->angular.z;

    if((msg->linear.x>=0)&&(msg->linear.y<0)){
        //s16DirectionAngle=(int16_t)(atan(msg->linear.x/((-1)*msg->linear.y))*180*100/PI);
        s16DirectionAngle=(int16_t)(18000-atan(msg->linear.x/(msg->linear.y*(-1)))*180*100/PI);
    }else if((msg->linear.x>=0)&&(msg->linear.y>0)){
        //s16DirectionAngle=(int16_t)(18000-atan(msg->linear.x/msg->linear.y)*180*100/PI);
        s16DirectionAngle=(int16_t)(atan(msg->linear.x/msg->linear.y)*180*100/PI);
    }else if((msg->linear.x<=0)&&(msg->linear.y<0)){
        //s16DirectionAngle=(int16_t)(atan(msg->linear.x/msg->linear.y)*180*100*(-1)/PI);
        s16DirectionAngle=(int16_t)((-18000)+atan(msg->linear.x/msg->linear.y)*180*100/PI);
    }else if((msg->linear.x<=0)&&(msg->linear.y>0)){
        //s16DirectionAngle=(int16_t)((-18000)+atan(((-1)*msg->linear.x)/msg->linear.y)*180*100/PI);
        s16DirectionAngle=(int16_t)(atan((msg->linear.x*(-1))/msg->linear.y)*180*100*(-1)/PI);
    }else if((msg->linear.x>0)&&(msg->linear.y==0)){
        s16DirectionAngle=9000;
    }else if((msg->linear.x<0)&&(msg->linear.y==0)){
        s16DirectionAngle=-9000;
    }else if((msg->linear.x==0)&&(msg->linear.y==0)){
        s16DirectionAngle=0;
    }

    u16LinearVelocity=(u_int16_t)(sqrt((msg->linear.x*msg->linear.x)+(msg->linear.y*msg->linear.y))*10000);
    s16AngularVelocity=msg->angular.z*180*100/PI;

    //ROS_INFO("%d,%d,%d",s16DirectionAngle,u16LinearVelocity,s16AngularVelocity);

    if(g_isCpuLittleEndian){
        union16.s16=s16DirectionAngle;
        ac[0]=union16.u8[0];
        ac[1]=union16.u8[1];
        union16.u16=u16LinearVelocity;
        ac[2]=union16.u8[0];
        ac[3]=union16.u8[1];
        union16.s16=s16AngularVelocity;
        ac[4]=union16.u8[0];
        ac[5]=union16.u8[1];
    }else{
        union16.s16=s16DirectionAngle;
        ac[0]=union16.u8[1];
        ac[1]=union16.u8[0];
        union16.u16=u16LinearVelocity;
        ac[2]=union16.u8[1];
        ac[3]=union16.u8[0];
        union16.s16=s16AngularVelocity;
        ac[4]=union16.u8[1];
        ac[5]=union16.u8[0];
    }
    if(nMotionUart.SetInstantVelocity(ac,strErr)==0){
       // ROS_INFO("set the velocity..");
    }else{
        ROS_ERROR("Can't set the velocity!Maybe the conmmunication is not OK!");
    }
    delete msg;
    time_BetweenDataPackage=time_PublishGeoTwistVelocity=GetNowTime();
}

void ClearEncoderCountCallback(const N_Robot_Topic::NMotionCtrlTopic_ClearEncoderCount_msg::ConstPtr& msg){
    Union16 union16;
    unsigned char ac[50];
    string strErr;
    if(msg->command==true){
        if(nMotionUart.ClearEncoderCount(ac,strErr)==0){

        }else {
           // ROS_ERROR("Can't clear the encoder count!");
        }
    }else{
        return ;
    }
    return ;
}

struct timeval timeVal1;
struct timezone timeZone;

long GetNowTime(void){
    long time;//ms
    gettimeofday(&timeVal1,NULL);
    time=(timeVal1.tv_sec-gTimeCurrentSecWhenOpenDevice)*1000+timeVal1.tv_usec/1000;
    return time;//ms
}

int main(int argc,char **argv){
    gettimeofday(&timeVal1,NULL);
    gTimeCurrentSecWhenOpenDevice=timeVal1.tv_sec;

    unsigned char ac[100];
    string strErr;
    string strPara1;
    int nErr;
    long time_PublishMotionStatus=0,//ms
            time_PublishUltrasonicData=0,
            time_PublishUltrasonicStatus=0,
            time_PublishEncoderCount=0,
            time_PublishBatteryVoltage=0;

    //judge the cup little endian?
    Union16  tempUnion16;
    tempUnion16.u16=0x0001;
    if(tempUnion16.u8[0]==0x01){
        g_isCpuLittleEndian=true;
    }else{
        g_isCpuLittleEndian=false;
    }

    if(argc>1){
        strPara1=argv[1];
    }else{
        strPara1="";
    }
    ros::init(argc,argv,"NMotionCtrlTopic");
    ros::NodeHandle n;
    ROS_INFO("Chengdu Hangfa N serials robot motion node for Topic.v1.0");
    //** set uart parameter
    if(strPara1.find("/dev/tty")==string::npos){
        nMotionUart.pcPortName=UARTPORTNAME_NMOTIONCTRL;//USBcom use PL2303 chip
    }else{
        nMotionUart.pcPortName=argv[1];
    }

    nMotionUart.nUartSpeed=115200;//9600
    nMotionUart.nUartFlowCtrl=0;
    nMotionUart.nUartDatabits=8;
    nMotionUart.nUartStopbits=1;
    nMotionUart.nParity='N';
#ifdef PROJ_DEBUG
    printf("UART Setting:port name =%s,speed=%d,flowctrl=%d,databits=%d,stopbits=%d,parity=%c\n",nMotionUart.pcPortName,nMotionUart.nUartSpeed,nMotionUart.nUartFlowCtrl,nMotionUart.nUartDatabits,nMotionUart.nUartStopbits,nMotionUart.nParity);
#endif
    //** open serial port
    nErr=nMotionUart.InitPort();
    if(nErr){
        ROS_INFO("Fail to init %s.",nMotionUart.pcPortName);
        return -1;
    }
    nMotionUart.ClearRcvBuf();
    //**
    ros::Publisher msgPubMotionStatus=n.advertise<N_Robot_Topic::NMotionCtrlTopic_MotionStatus_msg>("NMotionCtrlTopic/MotionStatus",2);
    ROS_INFO("topic NMotionCtrlTopic/MotionStatus OK.");
    ros::Publisher msgPubUltrasonicData=n.advertise<N_Robot_Topic::NMotionCtrlTopic_UltrasonicData_msg>("NMotionCtrlTopic/UltrasonicData",2);
    ROS_INFO("topic NMotionCtrlTopic/UltrasonicData OK.");
    ros::Publisher msgPubUltrasonicStatus=n.advertise<N_Robot_Topic::NMotionCtrlTopic_UltrasonicStatus_msg>("NMotionCtrlTopic/UltrasonicStatus",2);
    ROS_INFO("topic NMotionCtrlTopic/UltrasonicStatus OK.");
    ros::Publisher msgPubEncoderCount=n.advertise<N_Robot_Topic::NMotionCtrlTopic_EncoderCount_msg>("NMotionCtrlTopic/EncoderCount",2);
    ROS_INFO("topic NMotionCtrlTopic/EncoderCount OK.");
    ros::Publisher msgPubBatteryVoltage=n.advertise<N_Robot_Topic::NMotionCtrlTopic_BatteryVoltage_msg>("NMotionCtrlTopic/BatteryVoltage",2);
    ROS_INFO("topic NMotionCtrlTopic/BatteryVoltage OK.");

    ros::Subscriber msgSubSetInstantVelocity=n.subscribe("NMotionCtrlTopic/SetInstantVelocity",2,SetInstantVelocityCallback);
    ROS_INFO("topic NMotionCtrlTopic/SetInstantVelocity OK.");
    ros::Subscriber msgSubRosSetInstantVelocity=n.subscribe("NMotionCtrlTopic/GeoTwistSetInstantVelocity",2,GeoTwistSetInstantVelocityCallback);
    ROS_INFO("topic NMotionCtrlTopic/GeoTwistSetInstantVelocity OK.");
    ros::Subscriber msgSubClearEncoderCount=n.subscribe("NMotionCtrlTopic/ClearEncoderCount",2,ClearEncoderCountCallback);
    ROS_INFO("topic NMotionCtrlTopic/ClearEncoderCount OK.");

    N_Robot_Topic::NMotionCtrlTopic_MotionStatus_msg motionStatusMsg;
    N_Robot_Topic::NMotionCtrlTopic_UltrasonicData_msg ultrasonicDataMsg;
    N_Robot_Topic::NMotionCtrlTopic_UltrasonicStatus_msg ultrasonicStatusMsg;
    N_Robot_Topic::NMotionCtrlTopic_EncoderCount_msg encoderCountMsg;
    N_Robot_Topic::NMotionCtrlTopic_BatteryVoltage_msg batteryVoltageMsg;

    ros::Rate loopRate(1000);
    usleep(5000000);
    time_BetweenDataPackage=GetNowTime();
    //ROS_INFO("The current time is %ld (ms)",time_BetweenDataPackage);
    ROS_INFO("Robot Starts Working!");

    while(ros::ok()){//the  more front "front" means higher priority
        if((isAbleCommunication==true) && ((GetNowTime()-time_PublishEncoderCount)>=TIME_FREQ_ENCODER_COUNT)){
            isAbleCommunication=false;
            FucReadEncoderCount(ac,strErr,msgPubEncoderCount,encoderCountMsg);
            time_BetweenDataPackage=time_PublishEncoderCount=GetNowTime();
        }

        if((isAbleCommunication==true) &&((GetNowTime()-time_PublishGeoTwistVelocity)>=TIME_FREQ_GEOTWIST) ){
            ros::spinOnce();
        }

        if((isAbleCommunication==true) && ((GetNowTime()-time_PublishMotionStatus))>=TIME_FREQ_MOTION_STATUS){
            isAbleCommunication=false;
            FucReadMotionStatus(ac,strErr,msgPubMotionStatus,motionStatusMsg);
            time_BetweenDataPackage=time_PublishMotionStatus=GetNowTime();
        }

        if(isAbleCommunication==true && (GetNowTime()-time_PublishUltrasonicData)>=TIME_FREQ_ULTRASONIC_DATA){
            isAbleCommunication=false;
            FucReadUltrasonicData(ac,strErr,msgPubUltrasonicData,ultrasonicDataMsg);
            time_BetweenDataPackage=time_PublishUltrasonicData=GetNowTime();
        }

        if(isAbleCommunication==true && (GetNowTime()-time_PublishUltrasonicStatus)>=TIME_FREQ_ULTRASONIC_STATUS){
            isAbleCommunication=false;
            FucReadUltrasonicStatus(ac,strErr,msgPubUltrasonicStatus,ultrasonicStatusMsg);
            time_BetweenDataPackage=time_PublishUltrasonicStatus=GetNowTime();
        }

        if(isAbleCommunication==true && (GetNowTime()-time_PublishBatteryVoltage)>=TIME_FREQ_BATTERY_VOLTAGE){
            isAbleCommunication=false;
            FucReadBatteryVoltage(ac,strErr,msgPubBatteryVoltage,batteryVoltageMsg);
            time_BetweenDataPackage=time_PublishBatteryVoltage=GetNowTime();
        }

        if((isAbleCommunication==false) && ((GetNowTime()-time_BetweenDataPackage)>=TIME_BETWEEN_DATAPACKAGE)){
            isAbleCommunication=true;
        }
        usleep(200);
    }
    //  ros::spinOnce();
    //loopRate.sleep();
    return 0;
}

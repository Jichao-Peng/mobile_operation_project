#ifndef UARTNMotion_H
#define UARTNMotion_H
#include "UARTDev.h"
//#include <iostream>
#include <string>
  using namespace std;


class UartNMotion:public UARTDev{
public:
    UartNMotion();
    ~UartNMotion();

    unsigned char bytDevType;
    unsigned char bytDevInfo;

   int ReceiveFunction(const int nRcvLenEx,char *acRcvBuf,string &strErr);

    int ReadDevInfo(unsigned char  acData[],string & strErr);
    int ReadVersion(unsigned char  acData[],string &strErr);
    int Reboot(unsigned char  acData[],string &strErr);
    int ReadMotionStatus(unsigned char  acData[],string &strErr);
    int ResetAllMotorDriver(unsigned char  acData[],string &strErr);
    int ClearMotionBuff(unsigned char  acData[],string &strErr);
    int ClearErrFlag(unsigned char  acData[],string &strErr);
    int StartMotion(unsigned char  acData[],string &strErr);
    int SuspendMotion(unsigned char  acData[],string &strErr);
    int ContinueMotion(unsigned char  acData[],string &strErr);
    int StopMotion(unsigned char  acData[],string &strErr);
    int JumpToNextCmd(unsigned char  acData[],string &strErr);
    int StopMotionAndSetDir(unsigned char  acData[],string &strErr);
    int SetDirAfterMotion(unsigned char  acData[],string &strErr);
    int WaitTime(unsigned char  acData[],string &strErr);
    int SetInstantVelocity(unsigned char  acData[],string &strErr);
    int SMATSpeedMode(unsigned char  acData[],string &strErr);
    int CMATSpeedMode(unsigned char  acData[],string &strErr);
   // int CAATSpeedMode(unsigned char  acData[],string &strErr);
    int DefineMotorSpeed(unsigned char  acData[],string &strErr);
    int SMATPositionMode(unsigned char  acData[],string &strErr);
    int STATPositionMode(unsigned char  acData[],string &strErr);
    int CMATPositionMode(unsigned char  acData[],string &strErr);
    int CAATPositionMode(unsigned char  acData[],string &strErr);
    int JoyCmdMotion(unsigned char  acData[],string &strErr);
//kc_new

    int SavePara(unsigned char  acData[],string &strErr);
    int ReadSinglePara(unsigned char  acData[],string &strErr);
    int RecoverFactorySet(unsigned char  acData[],string &strErr);
    int SetSinglePara(unsigned char  acData[],string &strErr);
    int SetOrientation(unsigned char  acData[],string &strErr);
    int WaitForSomeTime(unsigned char  acData[],string &strErr);
    int CAATSpeedMode(unsigned char  acData[],string &strErr);
    int ReadBatteryVoltage(unsigned char  acData[],string &strErr);
    int ReadUltrasonicData(unsigned char  acData[],string &strErr);
    int ReadUltrasonicStatus(unsigned char  acData[],string &strErr);
    int ReadMotorVelocity(unsigned char  acData[],string &strErr);
    int ReadEncoderCount(unsigned char  acData[],string &strErr);
    int ClearEncoderCount(unsigned char  acData[],string &strErr);
private:
    bool isCpuLittleEndian;

};

#endif // UARTNMotion_H

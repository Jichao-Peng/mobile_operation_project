//
// Created by leo on 18-6-2.
//

#include "robot_base_odometry.h"

RobotBaseOdometry::RobotBaseOdometry(double wheel_radius, double base_width, double base_length, int deceleration_radio, int encoder_lines):
    kWheelRadius(wheel_radius),kBaseWidth(base_width),kBaseLength(base_length),kDecelerationRatio(deceleration_radio),kEncoderLines(encoder_lines)
{
    encoder_sub = node.subscribe("/NMotionCtrlTopic/EncoderCount",1000,&RobotBaseOdometry::EncoderCallBack,this);


    coeffiecient_t = 2*M_PI*kWheelRadius/(kDecelerationRatio*kEncoderLines*4);
    coeffiecient_k = (kBaseLength+kBaseWidth)/2;
    matrix_f.resize(3,4);
    matrix_f <<  0.25,     0.25,     0.25,     0.25,
                -0.25,     0.25,    -0.25,     0.25,
                -1/(4*coeffiecient_k),-1/(4*coeffiecient_k), 1/(4*coeffiecient_k), 1/(4*coeffiecient_k);
}

void RobotBaseOdometry::EncoderCallBack(const N_Robot_Topic::NMotionCtrlTopic_EncoderCount_msgConstPtr &Msg)
{
    if(Msg->isCommunicationOK)
    {
        Vector4d encoder,wheel_distance;
        Vector3d current_base_distance,privious_base_distance,base_velocity;
        //这里要调整顺序
        encoder[0] = -Msg->encoder2Count;
        encoder[1] = -Msg->encoder3Count;
        encoder[2] = Msg->encoder4Count;
        encoder[3] = Msg->encoder1Count;

        for(int i=0; i<4; i++)
        {
            wheel_distance[i] = encoder[i] * coeffiecient_t;
        }

        current_base_distance = matrix_f * wheel_distance;
        cout<<current_base_distance<<endl<<endl;
    }
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"robot_base_odometry");
    RobotBaseOdometry RobotBaseOdometry(203.2/2,595,479,32,2500);
    ros::spin();
    return 0;
}


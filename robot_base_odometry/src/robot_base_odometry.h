//
// Created by leo on 18-6-2.
//

#ifndef PROJECT_ROBOT_BASE_ODOMETRY_H
#define PROJECT_ROBOT_BASE_ODOMETRY_H

#include <math.h>
#include <ros/ros.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <N_Robot_Topic/NMotionCtrlTopic_EncoderCount_msg.h>//为嘛是红色我不知道，感觉应该是包的名字大写的原因

using namespace std;
using namespace Eigen;

class RobotBaseOdometry
{
public:
    RobotBaseOdometry(double wheel_radius, double base_width, double base_length, int deceleration_radio, int encoder_lines);

private:
    ros::NodeHandle node;
    ros::Subscriber encoder_sub;
    ros::Publisher odometry_pub;
    nav_msgs::Odometry odometry;
    ros::Time current_time,previous_time;
    tf::TransformBroadcaster odometry_broadcaster;
    Vector3d base_distance,base_velocity,base_distance_diff;
    Vector4d current_encoder,previous_encoder,encoder_diff;

    void EncoderCallBack(const N_Robot_Topic::NMotionCtrlTopic_EncoderCount_msgConstPtr &Msg);

    const double kWheelRadius;//轮子的直径
    const double kBaseWidth;//左右两轮中心距离
    const double kBaseLength;//前后两轮中心距离
    const int kDecelerationRatio;//轮子电机减速比
    const int kEncoderLines;//码盘线束

    double coeffiecient_k;//用于记录底盘长宽之和的系数
    double coeffiecient_t;//用于记录码盘值和轮子走过的距离之间的转化系数
    MatrixXd matrix_f;
};


#endif //PROJECT_ROBOT_BASE_ODOMETRY_H

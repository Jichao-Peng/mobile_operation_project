//
// Created by leo on 18-6-2.
//

#include "robot_base_odometry.h"

RobotBaseOdometry::RobotBaseOdometry(double wheel_radius, double base_width, double base_length, int deceleration_radio, int encoder_lines):
    kWheelRadius(wheel_radius),kBaseWidth(base_width),kBaseLength(base_length),kDecelerationRatio(deceleration_radio),kEncoderLines(encoder_lines)
{
    encoder_sub = node.subscribe("/NMotionCtrlTopic/EncoderCount",1000,&RobotBaseOdometry::EncoderCallBack,this);
    odometry_pub = node.advertise<nav_msgs::Odometry>("odom", 50);
    clear_pub = node.advertise<N_Robot_Topic::NMotionCtrlTopic_ClearEncoderCount_msg>("/NMotionCtrlTopic/ClearEncoderCount",50);

    coeffiecient_t = 2*M_PI*kWheelRadius/(kDecelerationRatio*kEncoderLines*4);
    coeffiecient_k = (kBaseLength+kBaseWidth)/2;
    matrix_f.resize(3,4);
    matrix_f <<  0.25,     0.25,     0.25,     0.25,
                -0.25,     0.25,    -0.25,     0.25,
                -1/(4*coeffiecient_k),-1/(4*coeffiecient_k), 1/(4*coeffiecient_k), 1/(4*coeffiecient_k);
    current_time = ros::Time::now();
    previous_time = ros::Time::now();
    base_distance = Vector3d::Zero();
    base_velocity = Vector3d::Zero();
    base_distance_diff = Vector3d::Zero();
    current_encoder = Vector4d::Zero();
    previous_encoder = Vector4d::Zero();
    encoder_diff = Vector4d::Zero();
}

void RobotBaseOdometry::EncoderCallBack(const N_Robot_Topic::NMotionCtrlTopic_EncoderCount_msgConstPtr &Msg)
{

    if(Msg->isCommunicationOK)
    {
        current_time = ros::Time::now();
        double dt = (current_time-previous_time).toSec();

        //这里要调整顺序
        current_encoder[0] = -Msg->encoder2Count;
        current_encoder[1] = -Msg->encoder3Count;
        current_encoder[2] = Msg->encoder4Count;
        current_encoder[3] = Msg->encoder1Count;
        encoder_diff = current_encoder - previous_encoder;

        //根据四个轮子绝对码盘值进行运动学正解，先求得当前机器人底盘速度，然后速度积分获得位置
        base_distance_diff = matrix_f * (encoder_diff * coeffiecient_t);
        base_velocity = base_distance_diff/dt;

        //由局部坐标系转化到全局坐标系下
        double delta_x = base_distance_diff[0]*cos(base_distance[2]) - base_distance_diff[1]*sin(base_distance[2]);
        double delta_y = base_distance_diff[0]*sin(base_distance[2]) + base_distance_diff[1]*cos(base_distance[2]);
        double delta_theta = base_distance_diff[2];

        base_distance[0] += delta_x;
        base_distance[1] += delta_y;
        base_distance[2] += delta_theta;

        //向前赋值
        previous_time = current_time;
        previous_encoder = current_encoder;

        //通过tf讲z轴转角转为四元数
        geometry_msgs::Quaternion odometry_quaternion = tf::createQuaternionMsgFromYaw(base_distance[2]);

        //发布odom和base_link的tf变换
        geometry_msgs::TransformStamped odometry_tf;
        odometry_tf.header.stamp = current_time;
        odometry_tf.header.frame_id = "odom";
        odometry_tf.child_frame_id = "base_link";
        odometry_tf.transform.translation.x = base_distance[0];
        odometry_tf.transform.translation.y = base_distance[1];
        odometry_tf.transform.translation.z = 0.0;
        odometry_tf.transform.rotation = odometry_quaternion;
        odometry_broadcaster.sendTransform(odometry_tf);

        //将odometry发布到odom的topic上
        nav_msgs::Odometry odometry;
        odometry.header.stamp = current_time;
        odometry.header.frame_id = "odom";
        odometry.child_frame_id = "base_link";
        odometry.pose.pose.position.x = base_distance[0];
        odometry.pose.pose.position.y = base_distance[1];
        odometry.pose.pose.position.z = 0.0;
        odometry.pose.pose.orientation = odometry_quaternion;
        odometry.twist.twist.linear.x = base_velocity[0];
        odometry.twist.twist.linear.y = base_velocity[1];
        odometry.twist.twist.angular.z = base_velocity[2];
        odometry_pub.publish(odometry);

        //cout<<base_distance<<endl<<endl;
        //cout<<current_base_velocity<<endl<<endl;
    }
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"robot_base_odometry");
    RobotBaseOdometry RobotBaseOdometry(0.2032/2,0.595,0.479,32,2500);//单位都是m
    ros::spin();
    return 0;
}


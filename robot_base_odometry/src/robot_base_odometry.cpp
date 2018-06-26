//
// Created by leo on 18-6-2.
//

#include "robot_base_odometry.h"

RobotBaseOdometry::RobotBaseOdometry(double wheel_radius, double base_width, double base_length, int deceleration_radio, int encoder_lines):
    kWheelRadius(wheel_radius),kBaseWidth(base_width),kBaseLength(base_length),kDecelerationRatio(deceleration_radio),kEncoderLines(encoder_lines)
{
    encoder_sub = node.subscribe("/NMotionCtrlTopic/EncoderCount",1000,&RobotBaseOdometry::EncoderCallBack,this);
    odometry_pub = node.advertise<nav_msgs::Odometry>("odom", 50);

    coeffiecient_t = 2*M_PI*kWheelRadius/(kDecelerationRatio*kEncoderLines*4);
    coeffiecient_k = (kBaseLength+kBaseWidth)/2;
    matrix_f.resize(3,4);
    matrix_f <<  0.25,     0.25,     0.25,     0.25,
                -0.25,     0.25,    -0.25,     0.25,
                -1/(4*coeffiecient_k),-1/(4*coeffiecient_k), 1/(4*coeffiecient_k), 1/(4*coeffiecient_k);
    current_time = ros::Time::now();
    previous_time = ros::Time::now();
    current_base_distance = Vector3d::Zero();
    previous_base_distance = Vector3d::Zero();
    current_base_velocity = Vector3d::Zero();
}

void RobotBaseOdometry::EncoderCallBack(const N_Robot_Topic::NMotionCtrlTopic_EncoderCount_msgConstPtr &Msg)
{
    if(Msg->isCommunicationOK)
    {
        current_time = ros::Time::now();
        double dt = (current_time-previous_time).toSec();
        Vector4d encoder,wheel_distance;
        //这里要调整顺序
        encoder[0] = -Msg->encoder2Count;
        encoder[1] = -Msg->encoder3Count;
        encoder[2] = Msg->encoder4Count;
        encoder[3] = Msg->encoder1Count;

        //根据四个轮子绝对码盘值进行运动学正解，求得底盘当前位置以及速度
        for(int i=0; i<4; i++)
        {
            wheel_distance[i] = encoder[i] * coeffiecient_t;
        }
        current_base_distance = matrix_f * wheel_distance;
        current_base_velocity = (current_base_distance-previous_base_distance)/dt;
        previous_base_distance = current_base_distance;
        previous_time = current_time;

        //通过tf讲z轴转角转为四元数
        geometry_msgs::Quaternion odometry_quaternion = tf::createQuaternionMsgFromYaw(current_base_distance[2]);

        //发布odom和base_link的tf变换
        geometry_msgs::TransformStamped odometry_tf;
        odometry_tf.header.stamp = current_time;
        odometry_tf.header.frame_id = "odom";
        odometry_tf.child_frame_id = "base_link";
        odometry_tf.transform.translation.x = current_base_distance[0];
        odometry_tf.transform.translation.y = current_base_distance[1];
        odometry_tf.transform.translation.z = 0.0;
        odometry_tf.transform.rotation = odometry_quaternion;
        odometry_broadcaster.sendTransform(odometry_tf);

        //将odometry发布到odom的topic上
        nav_msgs::Odometry odometry;
        odometry.header.stamp = current_time;
        odometry.header.frame_id = "odom";
        odometry.child_frame_id = "base_link";
        odometry.pose.pose.position.x = current_base_distance[0];
        odometry.pose.pose.position.y = current_base_distance[1];
        odometry.pose.pose.position.z = 0.0;
        odometry.pose.pose.orientation = odometry_quaternion;
        odometry.twist.twist.linear.x = current_base_velocity[0];
        odometry.twist.twist.linear.y = current_base_velocity[1];
        odometry.twist.twist.angular.z = current_base_velocity[2];
        odometry_pub.publish(odometry);

        cout<<current_base_distance<<endl<<endl;
        cout<<current_base_velocity<<endl<<endl;
    }
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"robot_base_odometry");
    RobotBaseOdometry RobotBaseOdometry(0.2032/2,0.595,0.479,32,2500);//单位都是m
    ros::spin();
    return 0;
}


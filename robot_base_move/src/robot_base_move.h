//
// Created by robot2 on 18-9-19.
//

#ifndef PROJECT_ROBOT_BASE_MOVE_H
#define PROJECT_ROBOT_BASE_MOVE_H

#include <ros/ros.h>
#include <robot_base_move/base_move.h>
#include <nav_msgs/Odometry.h>
#include <move_base_msgs/MoveBaseGoal.h>
#include <geometry_msgs/Twist.h>
#include <eigen3/Eigen/Dense>
#include <std_msgs/Bool.h>

using namespace std;

class RobotBaseMove
{
    struct BasePose
    {
        double x;
        double y;
        double z;
    };


public:
    RobotBaseMove();
    ~RobotBaseMove();
    void Run();

private:
    ros::NodeHandle node;
    ros::Subscriber odometry_sub;
    ros::Subscriber move_sub;
    ros::Publisher move_state_pub;
    ros::ServiceServer move_ser;
    ros::Publisher cmd_vel_pub;

    BasePose cur_pose;
    BasePose tar_pose;

    double vel_x_threshold = 0.2;
    double vel_y_threshold = 0.2;
    double vel_z_threshold = 0.15;

    bool move_flag = false;

    void OdometryCallBack(nav_msgs::OdometryConstPtr msg);
    void MoveCallBack(move_base_msgs::MoveBaseGoal goal);
    bool MoveService(robot_base_move::base_moveRequest &req, robot_base_move::base_moveResponse &res);
    void Ouaterniond2Euler(const geometry_msgs::Pose& quat_pose, BasePose& euler_pose);
};


#endif //PROJECT_ROBOT_BASE_MOVE_H

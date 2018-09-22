//
// Created by Zyccc on 18-9-21.
//

#ifndef PROJECT_NEW_ROBOT_BASE_CONTROL_H
#define PROJECT_NEW_ROBOT_BASE_CONTROL_H

#include <cv.h>
#include <map>
#include <vector>
#include <string>
#include <ros/ros.h>
#include "robot_base_control/base_goal.h"
#include <nav_msgs/Odometry.h>
#include <move_base_msgs/MoveBaseGoal.h>
#include <geometry_msgs/Twist.h>
#include <eigen3/Eigen/Dense>


using namespace std;

class RobotBaseControl
{
    
    struct BasePose
    {
        double x;
        double y;
        double z;
    };

public:
    RobotBaseControl();
    ~RobotBaseControl();
    void Run();

private:
    ros::NodeHandle node;

    ros::ServiceServer goal_ser;
    ros::Subscriber odometry_sub;
    ros::Publisher cmd_vel_pub;

    bool ReadPosData();
    bool GoalService(robot_base_control::base_goalRequest &req, robot_base_control::base_goalResponse &res);
    void OdometryCallBack(nav_msgs::OdometryConstPtr msg);
    void Ouaterniond2Euler(const geometry_msgs::Pose& quat_pose, BasePose& euler_pose);
    void GetTargetPose(const string point);

    map<string,vector<float> > path;

    bool finish_flag = true;
    bool move_flag = false;
    bool point_flag = true;
    BasePose cur_pose;
    BasePose tar_pose;
    
};


#endif //PROJECT_NEW_ROBOT_BASE_CONTROL_H
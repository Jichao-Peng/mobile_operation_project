//
// Created by leo on 18-9-18.
//

#ifndef PROJECT_ROBOT_BASE_CONTROL_H
#define PROJECT_ROBOT_BASE_CONTROL_H

#include <cv.h>
#include <map>
#include <vector>
#include <string>
#include <ros/ros.h>
#include "robot_base_move/base_move.h"
#include "robot_base_control/base_goal.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>

using namespace std;

class RobotBaseControl
{
public:
    RobotBaseControl();
    ~RobotBaseControl();
    void Run();

private:
    ros::NodeHandle node;
    ros::Subscriber goal_sub;
    ros::Publisher goal_state_pub;
    ros::ServiceServer goal_ser;
    ros::ServiceClient move_cli;
    ros::Publisher move_pub;
    ros::Subscriber move_state_sub;
    actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>* move_base_client;


    void GoalCallBack(const std_msgs::StringConstPtr &msg);
    bool GoalService(robot_base_control::base_goalRequest &req, robot_base_control::base_goalResponse &res);
    void MoveStateCallBack(const std_msgs::BoolConstPtr &msg);


    map<string,vector<float> > path;
    bool finish_flag = true;
    bool ReadPosData();
};


#endif //PROJECT_ROBOT_BASE_CONTROL_H

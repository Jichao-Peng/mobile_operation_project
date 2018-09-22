#include <ros/ros.h>
#include "iomanip"
#include <iostream>   
#include "sstream"
#include "moveit/move_group_interface/move_group.h"
#include "moveit/robot_model_loader/robot_model_loader.h"
#include "moveit/robot_model/robot_model.h"
#include "moveit/robot_state/robot_state.h"
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include "control_msgs/FollowJointTrajectoryActionGoal.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/String.h"
#include <tf2/convert.h>
#include "Eigen/Core"
#include "Eigen/Geometry"
#include <tf2_eigen/tf2_eigen.h>
#include "std_msgs/Bool.h"


#define NUMBER 20 
typedef actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> Client;
class move_robot
{//定义一个和运动相关的类，主要用来获取当前的位恣
public:
    move_robot():group("manipulator"),robot_model_loader("robot_description"),kinematic_model(robot_model_loader.getModel()),
                kinematic_state(*group.getCurrentState()),joint_model_group(kinematic_model->getJointModelGroup("manipulator"))
    {
        Client ac("follow_joint_trajectory", true);
        if (!ac.waitForServer(ros::Duration(1.0)))
        {
            ROS_ERROR("Could not connect to action server");
            exit(-1);
            robot_status = 0;
        }
        else
        {
            ROS_INFO("Connecte with UR10 Now!");
            robot_status = 1;
        }
    }
    moveit::planning_interface::MoveGroup group;
    robot_model_loader::RobotModelLoader robot_model_loader;
    robot_model::RobotModelPtr kinematic_model;
    moveit::core::RobotState kinematic_state;
    const robot_state::JointModelGroup* joint_model_group;
    int robot_status;
};


class MAIN_NODE
{
public:
    MAIN_NODE()
    {
        ROS_INFO("Ready to accept new task!");
        goal_state_msg.data = false;
        goal_state_flag = 0;

        goal_pub = nh_.advertise<std_msgs::String>("base_goal_topic", 1000);
        goal_state_sub = nh_.subscribe("base_goal_state_topic", 1000, &MAIN_NODE::BaseGoalStateCallback, this);   //小车到达目标时，发1到base_goal_state_topic
        ros::Duration(1.0).sleep();
    }
    void start();

private:
    ros::NodeHandle nh_;
    ros::Subscriber goal_state_sub;
    ros::Publisher goal_pub;

    std_msgs::String goal_msg;
    std_msgs::Bool goal_state_msg;
    int goal_state_flag;
    
    geometry_msgs::Pose look_pose;
    geometry_msgs::Pose grasp_pose;
    geometry_msgs::Pose release_pose;

    // move_robot move;

    // function
    void BaseGoalStateCallback(const std_msgs::BoolConstPtr& msg);
};


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "main_node");
    ros::AsyncSpinner spinner(1);
    spinner.start();
    MAIN_NODE main_node;
    main_node.start();
    ros::waitForShutdown();             // 等待系统关闭
    return 0;
}

void MAIN_NODE::start()
{
    goal_msg.data = "A1";
    goal_pub.publish(goal_msg);
    ros::Duration(0.5).sleep();
    while (ros::ok())
    {
        if(goal_state_flag == 1)
        {
            break;
        }
        else
        {
            ROS_INFO("AGV has arrived A1.");                                // ? ? ? ? ?
        }
    }

    ros::Duration(1).sleep();

    goal_state_flag = 0;
    goal_msg.data = "A2";
    goal_pub.publish(goal_msg);
    ros::Duration(0.5).sleep();
    while (ros::ok())
    {
        if(goal_state_flag == 1)
        {
            break;
        }
        else
        {
            ROS_INFO("AGV has arrived A2.");
        }
    }
    goal_state_flag = 0;

    ROS_INFO("Program finished");
}

void MAIN_NODE::BaseGoalStateCallback(const std_msgs::BoolConstPtr& msg)
{
    if(goal_state_flag == 0) goal_state_flag = 1;                           //车到达时， goal_state_flag = 1



}
// bool MAIN_NODE::input_callback(jrc_main::input::Request& req, jrc_main::input::Response& res)
// {
//     req.names.resize(NUMBER);
//     req.numbers.resize(NUMBER);
//     res.left_numbers.resize(NUMBER);
    
//     for(int i = 0; i < NUMBER; i ++)
//     {
//         res.left_numbers[i].data = req.numbers[i].data;
//     }
//     // 在这个节点里面实现各种逻辑
//     ROS_INFO("Requst information is:");
//     ShowInputSrv(req, res);

//     // 下面开始真正的逻辑
//     agv_srv.request.pose.data = "A1";
//     agv_srv.response.state.data = false;

//     // AGV先到达起始点
//     if(agv_client.call(agv_srv))
//     {
//         ROS_INFO("Success to connect agv server");
//         if(agv_srv.response.state.data == true)
//         {
//             ROS_INFO("AGV has arrived at A1");
//         }        
//     }

//     // // 机械臂运动
//     // move.group.setMaxAccelerationScalingFactor(1.0);
//     // move.group.setMaxVelocityScalingFactor(1.0);
//     // move.group.setPoseTarget(look_pose);
//     // move_group.move();
//     // ros::Duration(0.1).sleep();

//     agv_srv.request.pose.data = "A2";
//     agv_srv.response.state.data = false;

//     if(agv_client.call(agv_srv))
//     {
//         if(agv_srv.response.state.data == true)
//         {
//             ROS_INFO_STREAM("AGV has arrived at "<<agv_srv.request.pose.data);
//         }        
//     }
//     // 以上主要测试主节点和AGV之间的通讯和控制

//     if(grasp_client.call(grasp_srv))
//     {
//         ROS_INFO("Success to connect grasp server");
//     }
//     // grasp_pose = grasp_srv.response.target_pose;
//     // move_group.setPoseTarget(grasp_pose);
//     // ros::Duration(0.1).sleep();
//     // 手爪的运动
//     /*


//     */







// }

// int FindIndex(jrc_main::input::Request& req, std_msgs::String& str)
// {
//     req.names.resize(NUMBER);
//     int flag = 100; // 100 代表没有意义
//     for(int i = 0 ; i < NUMBER; i ++)
//     {
//         if(str.data.compare(req.names[i].data) == 0)
//         {
//             flag = i;
//             break;
//         }
//     }
//     return flag;
// }

// void MAIN_NODE::ShowInputSrv(jrc_main::input::Request& req, jrc_main::input::Response& res)
// {
//     using namespace std;
//     req.names.resize(NUMBER);
//     req.numbers.resize(NUMBER);
//     res.left_numbers.resize(NUMBER);
//     int kongge = 20;
//     cout<<setw(kongge/2)<<"object names"<<setw(kongge)<<"target numbers"<<setw(kongge)<<"left numbers"<<endl;
//     for(int i = 0; i < NUMBER; i ++)
//     {
//         cout<<setw(kongge/2)<<req.names[i].data<<setw(kongge)<<req.numbers[i].data<<setw(kongge)<<res.left_numbers[i].data<<endl;
//     }
//     cout<<endl;
// }
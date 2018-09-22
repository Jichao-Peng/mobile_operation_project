

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
#include "jrc_main/input.h"
#include "jrc_main/agv.h"
#include "jrc_main/grasp.h"


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
        // look pose初始化
        // release_pose初始化



        agv_client = nh_.serviceClient<jrc_main::agv>("agv_service");
        grasp_client = nh_.serviceClient<jrc_main::grasp>("grasp_service");
        input_server = nh_.advertiseService("input_service", &MAIN_NODE::input_callback, this);
        ros::Duration(0.6).sleep();
        ROS_INFO("Ready to accept new task!");
    }

private:
    ros::NodeHandle nh_;

    ros::ServiceServer input_server;
    ros::ServiceClient agv_client;
    ros::ServiceClient grasp_client;


    jrc_main::agv agv_srv;
    jrc_main::grasp grasp_srv;

    geometry_msgs::Pose look_pose;
    geometry_msgs::Pose grasp_pose;
    geometry_msgs::Pose release_pose;

    // move_robot move;

    // function
    bool input_callback(jrc_main::input::Request& req, jrc_main::input::Response& res);
    void ShowInputSrv(jrc_main::input::Request& req, jrc_main::input::Response& res);
    int FindIndex(jrc_main::input::Request& req, std_msgs::String& string);
};


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "main_node");
    ros::AsyncSpinner spinner(1);
    spinner.start();
    MAIN_NODE main_node;
    ros::waitForShutdown();             // 等待系统关闭
    return 0;
}


bool MAIN_NODE::input_callback(jrc_main::input::Request& req, jrc_main::input::Response& res)
{
    req.names.resize(NUMBER);
    req.numbers.resize(NUMBER);
    res.left_numbers.resize(NUMBER);
    
    for(int i = 0; i < NUMBER; i ++)
    {
        res.left_numbers[i].data = req.numbers[i].data;
    }
    // 在这个节点里面实现各种逻辑
    ROS_INFO("Requst information is:");
    ShowInputSrv(req, res);

    // 下面开始真正的逻辑
    agv_srv.request.pose.data = "A1";
    agv_srv.response.state.data = false;

    // AGV先到达起始点
    if(agv_client.call(agv_srv))
    {
        ROS_INFO("Success to connect agv server");
        if(agv_srv.response.state.data == true)
        {
            ROS_INFO("AGV has arrived at A1");
        }        
    }

    // // 机械臂运动
    // move.group.setMaxAccelerationScalingFactor(1.0);
    // move.group.setMaxVelocityScalingFactor(1.0);
    // move.group.setPoseTarget(look_pose);
    // move_group.move();
    // ros::Duration(0.1).sleep();

    agv_srv.request.pose.data = "A2";
    agv_srv.response.state.data = false;

    if(agv_client.call(agv_srv))
    {
        if(agv_srv.response.state.data == true)
        {
            ROS_INFO_STREAM("AGV has arrived at "<<agv_srv.request.pose.data);
        }        
    }
    // 以上主要测试主节点和AGV之间的通讯和控制

    if(grasp_client.call(grasp_srv))
    {
        ROS_INFO("Success to connect grasp server");
    }
    // grasp_pose = grasp_srv.response.target_pose;
    // move_group.setPoseTarget(grasp_pose);
    // ros::Duration(0.1).sleep();
    // 手爪的运动
    /*


    */







}

int FindIndex(jrc_main::input::Request& req, std_msgs::String& str)
{
    req.names.resize(NUMBER);
    int flag = 100; // 100 代表没有意义
    for(int i = 0 ; i < NUMBER; i ++)
    {
        if(str.data.compare(req.names[i].data) == 0)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

void MAIN_NODE::ShowInputSrv(jrc_main::input::Request& req, jrc_main::input::Response& res)
{
    using namespace std;
    req.names.resize(NUMBER);
    req.numbers.resize(NUMBER);
    res.left_numbers.resize(NUMBER);
    int kongge = 20;
    cout<<setw(kongge/2)<<"object names"<<setw(kongge)<<"target numbers"<<setw(kongge)<<"left numbers"<<endl;
    for(int i = 0; i < NUMBER; i ++)
    {
        cout<<setw(kongge/2)<<req.names[i].data<<setw(kongge)<<req.numbers[i].data<<setw(kongge)<<res.left_numbers[i].data<<endl;
    }
    cout<<endl;
}

// bool TF_IMAGE_CLIENT::voice_callback(grasp::Voice_status::Request& req, grasp::Voice_status::Response& res)
// {
//     ROS_INFO_STREAM("Request information is: "<<req.object.data<<" "<<req.place.data);
        
//     while (ros::ok())
//     {
//         if(image_flag == 1 && cloud_flag == 1)
//         {

//             // 先执行FCN图像分割操作
//             ros::service::waitForService("fcn_service");
//             ROS_INFO("Now the program is processed by FCN network! Please wait!");
//             if(fcn_client_.call(tf_image_))
//             {
//                 ROS_INFO("FCN network has been finished!");
//                 // ROS_INFO_STREAM("Image shape is: "<<tf_image_.response.output_image.height<<" "<<tf_image_.response.output_image.width);
//                 image_out = tf_image_.response.output_image;
//                 image_pub_flag = 1;


//                 icp_.request.index_image = tf_image_.response.output_image;
//                 icp_.request.object.data = req.object.data;
//             }
//             else
//             {
//                 ROS_ERROR("FCN request failed");
//                 return false;
//             }

//             // 然后执行ICP操作  
//             ros::service::waitForService("icp_service");
//             ROS_INFO("Now the program is caculating object pose! Please wait!");
//             if(icp_client_.call(icp_))
//             {
//                 ROS_INFO("ICP has been finished");
//                 ROS_INFO_STREAM("The transmation between object and camera is: "<<icp_.response.object_pose);
//                 grasp_.request.object_pose = icp_.response.object_pose;
//             }
//             else
//             {
//                 ROS_ERROR("ICP request failed");
//                 return false;
//             }

//             // // 最后执行机械臂运动的操作
//             // while (ros::ok())
//             // {
//             //     if(move.robot_status == 0)
//             //     {
//             //         ROS_ERROR("Please make sure the robot is connected with computer");
//             //         ros::Duration(0.2).sleep();
//             //     }
//             //     else
//             //     {
//             //         ros::service::waitForService("grasp_service");
//             //         ROS_INFO("Robot is start moving, watch out!");
//             //         if(grasp_client_.call(grasp_))
//             //         {
//             //             ROS_INFO("The object has been picked!");
//             //             ROS_INFO_STREAM("Grasp status is: "<<grasp_.response.grasp_status.data);
//             //         }
//             //         else
//             //         {
//             //             ROS_INFO("Grasp request failed!");
//             //             return false;
//             //         }

//             //         break;
//             //     }
//             // }  

//             break;

//         } 
//         else
//         {
//             ROS_WARN("No image and point cloud data, please make sure the realsense camera is working in ROS!");
//             ros::Duration(0.2).sleep();
//         }
//     }

//     // res.status.data = grasp_.response.grasp_status.data;
//     res.status.data = "Success";
//     return true;
// }


// void TF_IMAGE_CLIENT::cloud_cb(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
// {
//     if(cloud_flag == 0) cloud_flag = 1;
//     icp_.request.cloud = *cloud_msg;
// }

// void TF_IMAGE_CLIENT::image_callback(const sensor_msgs::ImageConstPtr& msg)
// {
//     if(image_flag == 0)image_flag = 1;
//     tf_image_.request.image = *msg;

//     if (image_pub_flag == 1)
//     {
//         cv::Mat temp_image;
//         cv_bridge::CvImagePtr cv_ptr;
//         try  
//         {  
//             cv_ptr =  cv_bridge::toCvCopy(image_out, sensor_msgs::image_encodings::TYPE_8UC1);
//             cv::equalizeHist(cv_ptr->image, cv_ptr->image);
//             // cv::imshow("image",cv_ptr->image);
//             // cv::waitKey(0);
//         }  
//         catch(cv_bridge::Exception& e)
//         {  
//             ROS_ERROR("cv_bridge exception: %s", e.what());  
//             return;  
//         }     
//         image_pub_.publish(cv_ptr->toImageMsg());
//     }
// }
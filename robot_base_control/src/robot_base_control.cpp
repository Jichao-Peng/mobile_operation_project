//
// Created by leo on 18-9-18.
//

#include "robot_base_control.h"

RobotBaseControl::RobotBaseControl()
{
    ReadPosData();

    goal_sub = node.subscribe("base_goal_topic",1000,&RobotBaseControl::GoalCallBack,this);
    goal_state_pub = node.advertise<std_msgs::Bool>("base_goal_state_topic",50);
    goal_ser = node.advertiseService("base_goal_service",&RobotBaseControl::GoalService,this);
    move_cli = node.serviceClient<robot_base_move::base_move>("base_move_service");
    move_pub = node.advertise<move_base_msgs::MoveBaseGoal>("base_move_topic",50);
    move_state_sub = node.subscribe("base_move_state_topic",50,&RobotBaseControl::MoveStateCallBace,this);
    move_base_client = new actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>("move_base", true);

//****************** 勿删 ******* move_base版 ******* 勿删 *****************************
//    while(!move_base_client->waitForServer(ros::Duration(5.0)))
//    {
//         cout<<"Waiting for the move_base action server to come up"<<endl;
//    }
//****************** 勿删 ******* move_base版 ******* 勿删 *****************************
}

RobotBaseControl::~RobotBaseControl()
{
    delete move_base_client;
}

void RobotBaseControl::Run()
{
    while(ros::ok())
    {
        if(finish_flag)
        {
            cout<<"Ready"<<endl;
        }
        ros::Rate Rate(1);
        Rate.sleep();
        ros::spinOnce();
    }
}

void RobotBaseControl::MoveStateCallBace(const std_msgs::BoolConstPtr &msg)
{
    if(msg->data == 1)
    {
        cout << "Robot get the goal,Please input the next point" << endl;
        std_msgs::Bool finish_msg;
        finish_msg.data = 1;
        goal_state_pub.publish(finish_msg);
        finish_flag = true;
    }
}

//Topic版本对应的robot_base_move里面也是topic版本
void RobotBaseControl::GoalCallBack(const std_msgs::StringConstPtr &msg)
{
    string point = msg->data;
    map<string,vector<float> >::iterator it = path.find(point);
    if(it != path.end())
    {
        if(it->second.size() == 7)
        {
            move_base_msgs::MoveBaseGoal goal;
            goal.target_pose.pose.position.x = it->second.at(0);
            goal.target_pose.pose.position.y = it->second.at(1);
            goal.target_pose.pose.position.z = it->second.at(2);
            goal.target_pose.pose.orientation.x = it->second.at(3);
            goal.target_pose.pose.orientation.y = it->second.at(4);
            goal.target_pose.pose.orientation.z = it->second.at(5);
            goal.target_pose.pose.orientation.w = it->second.at(6);

            ROS_INFO("Set the goal");
            if(finish_flag)
            {
                ROS_INFO("Sending goal");
                move_pub.publish(goal);
                finish_flag = false;
            }
        }
        else
        {
            cout<<"The pose is wrong"<<endl;
        }
    }
    else
    {
        cout<<"Can't find the point in the path"<<endl;
    }
}

bool RobotBaseControl::GoalService(robot_base_control::base_goalRequest &req,
                                   robot_base_control::base_goalResponse &res)
{

}

//****************** 勿删 ******* move_base版 ******* 勿删 *****************************
//bool RobotBaseControl::GoalService(robot_base_control::base_goalRequest &req,
//                                   robot_base_control::base_goalResponse &res)
//{
//    string point = req.point;
//    map<string,vector<float> >::iterator it = path.find(point);
//    if(it != path.end())
//    {
//        if(it->second.size() == 7)
//        {
//            move_base_msgs::MoveBaseGoal goal;
//
//            goal.target_pose.header.frame_id = "map";
//            goal.target_pose.header.stamp = ros::Time::now();
//
//            goal.target_pose.pose.position.x = it->second.at(0);
//            goal.target_pose.pose.position.y = it->second.at(1);
//            goal.target_pose.pose.position.z = it->second.at(2);
//            goal.target_pose.pose.orientation.x = it->second.at(3);
//            goal.target_pose.pose.orientation.y = it->second.at(4);
//            goal.target_pose.pose.orientation.z = it->second.at(5);
//            goal.target_pose.pose.orientation.w = it->second.at(6);
//            cout<<"The goal is "<<goal.target_pose.pose<<endl;
//
//            ROS_INFO("Sending goal");
//            move_base_client->sendGoal(goal);
//
//            move_base_client->waitForResult();
//
//            if(move_base_client->getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
//            {
//                ROS_INFO("Hooray, the base moved to the goal");
//                res.flag = 0;
//                return true;
//            }
//            else
//            {
//                ROS_INFO("The base failed to move forward to the goal");
//                res.flag = 1;
//                return false;
//            }
//
//        }
//        else
//        {
//            cout<<"The pose is wrong"<<endl;
//            res.flag = 0;
//            return false;
//        }
//    }
//    else
//    {
//        cout<<"Can't find the point in the path"<<endl;
//        res.flag = 0;
//        return false;
//    }
//}
//
//void RobotBaseControl::GoalCallBack(const std_msgs::StringConstPtr &msg)
//{
//    string point = msg->data;
//    map<string,vector<float> >::iterator it = path.find(point);
//    if(it != path.end())
//    {
//        if(it->second.size() == 7)
//        {
//            move_base_msgs::MoveBaseGoal goal;
//
//            goal.target_pose.header.frame_id = "map";
//            goal.target_pose.header.stamp = ros::Time::now();
//
//            goal.target_pose.pose.position.x = it->second.at(0);
//            goal.target_pose.pose.position.y = it->second.at(1);
//            goal.target_pose.pose.position.z = it->second.at(2);
//            goal.target_pose.pose.orientation.x = it->second.at(3);
//            goal.target_pose.pose.orientation.y = it->second.at(4);
//            goal.target_pose.pose.orientation.z = it->second.at(5);
//            goal.target_pose.pose.orientation.w = it->second.at(6);
//            cout<<"The goal is "<<goal.target_pose.pose<<endl;
//
//            ROS_INFO("Sending goal");
//            move_base_client->sendGoal(goal);
//
//            move_base_client->waitForResult();
//
//            if(move_base_client->getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
//                 ROS_INFO("Hooray, the base moved 1 meter forward");
//               else
//                 ROS_INFO("The base failed to move forward 1 meter for some reason");
//        }
//        else
//        {
//            cout<<"The pose is wrong"<<endl;
//        }
//
//
//    }
//    else
//    {
//        cout<<"Can't find the point in the path"<<endl;
//    }
//}
//****************** 勿删 ******* move_base版 ******* 勿删 *****************************

//读取数据,读取路径A上的坐标点，在position.xml中修改坐标点的同时需要修改A_NUM;
//TODO:感觉这种存储数据点的方式不是很理想，如果插点的话会比较麻烦，之后再修改
bool RobotBaseControl::ReadPosData()
{
    cv::FileStorage fs("/home/robot2/catkin_ws/src/robot_base_control/position.xml",cv::FileStorage::READ);

    if(fs.isOpened())
    {
        //读取路径点
        try
        {
            vector<string> points;
            fs["points"]>>points;
            for(vector<string>::iterator it = points.begin();it != points.end();it++)
            {
                string point = *it;
                vector<float> pose;
                fs[point]>>pose;

                path[point]=pose;
            }
        }
        catch(cv::Exception &e)
        {
            return false;
        }


    }
    else
    {
        return false;
    }

    //打印路径点
    cout<<"Robot base's path point is: "<<endl;
    for(map<string,vector<float> >::iterator it = path.begin();it != path.end();++it)
    {
        cout<<it->first<<": ";
        for (vector<float>::iterator itt = it->second.begin(); itt != it->second.end(); ++itt)
        {
            cout.setf(ios::showpoint);
            cout.precision(3);
            cout.setf(ios::fixed);
            cout << *itt << " ";
        }
        cout<<endl;
    }

    fs.release();
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"robot_base_control");
    RobotBaseControl RobotBaseControl;//单位都是m
    RobotBaseControl.Run();
    ros::spin();
    return 0;
}
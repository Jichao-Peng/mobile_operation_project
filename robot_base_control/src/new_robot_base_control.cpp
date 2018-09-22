//
// Created by Zyccc on 18-9-21.
//

#include "new_robot_base_control.h"

RobotBaseControl::RobotBaseControl()
{
    ReadPosData();

    goal_ser = node.advertiseService("base_goal_service",&RobotBaseControl::GoalService,this);
    odometry_sub = node.subscribe("odom", 50, &RobotBaseControl::OdometryCallBack, this);             //接收odom消息，转化为 cur_pose
    cmd_vel_pub = node.advertise<geometry_msgs::Twist>("cmd_vel", 50);
}


RobotBaseControl::~RobotBaseControl()
{
    
}

void RobotBaseControl::Run()
{
    while(ros::ok())
    {
        if(finish_flag)
        {
            cout<<"AGV is Ready to go ! Please send the target point !"<<endl;
        }
        ros::Rate Rate(0.2);
        Rate.sleep();
        ros::spinOnce();
    }
}

void RobotBaseControl::OdometryCallBack(const nav_msgs::OdometryConstPtr msg)                       //提供 cur_pose
{
    Ouaterniond2Euler(msg->pose.pose, cur_pose);
}

void RobotBaseControl::Ouaterniond2Euler(const geometry_msgs::Pose &quat_pose, BasePose &euler_pose)
{
    euler_pose.x = quat_pose.position.x;
    euler_pose.y = quat_pose.position.y;

    Eigen::Quaterniond q(quat_pose.orientation.x, quat_pose.orientation.y, quat_pose.orientation.z,
                         quat_pose.orientation.w);
    Eigen::Matrix3d Rx = q.toRotationMatrix();
    Eigen::Vector3d eular = Rx.eulerAngles(2, 1, 0);
    euler_pose.z = eular[2];
}

void RobotBaseControl::GetTargetPose(const string point)                                            //在 service 的回调函数中调用此函数，设置 tar_pose
{
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
                ROS_INFO("Settinging goal to Base_Pose");
                Ouaterniond2Euler(goal.target_pose.pose, tar_pose);                                 //设置 tar_pose
                finish_flag = false; 
                move_flag = true;
                point_flag = true;                                                                   //设置完 tar_pose 后， finish_flag = 0, move_flag = 1
            }
        }
        else
        {
            cout<<"The pose is wrong"<<endl;
            point_flag = false;
        }
    }
    else
    {
        cout<<"Can't find the point in the path"<<endl;
        point_flag = false;
    }
}




bool RobotBaseControl::GoalService(robot_base_control::base_goalRequest &req,
                                   robot_base_control::base_goalResponse &res)
{
    GetTargetPose(req.point);                                                                               //设置 tar_pose
    if(point_flag == false)
    {
        ROS_INFO("Something wrong with the assigned point !");
        ROS_INFO("Please send the right point !");
        res.flag = false;
        return true;                                                                //如果 point_flag = 0,直接跳出 service 
    }

    ROS_INFO("AGV starts running !");
    while (ros::ok())
    {
        if (move_flag)                                                               //move_flag = 1时运动， move_flag = 0 时停止
        {
            
            //cout<<"Running"<<endl;
            double det_x, det_y, det_z;
            double vel_x_threshold = 0.2;
            double vel_y_threshold = 0.2;
            double vel_z_threshold = 0.15;
            geometry_msgs::Twist vel;
            det_x = tar_pose.x - cur_pose.x;
            det_y = tar_pose.y - cur_pose.y;
            det_z = tar_pose.z - cur_pose.z;
            //cout << det_x << " " << det_y << " " << det_z << endl;
            double det_x_local = det_x*cos(cur_pose.z) + det_y*sin(cur_pose.z);
            double det_y_local = -det_x*sin(cur_pose.z) + det_y*cos(cur_pose.z);

            if (abs(det_z) < 0.05)
            {
                if (abs(det_x) < 0.005 && abs(det_y) < 0.005)
                {
                    ROS_INFO("AGV has arrived the goal point !");
                    cout << "Residual error to the goal point" << endl;
                    cout << "det_x = " << det_x << "\ndet_y = " << det_y << "\ndet_z = " << det_z << endl;

                    move_flag = false;
                    finish_flag = true;                                                 //到达目标后， move_flag = 0, finish_flag = 1
                    res.flag = true;
                    return true;
                }
                else
                {
                    vel.linear.x = det_x_local;
                    vel.linear.y = det_y_local;

                    //限幅
                    if (vel.linear.x > vel_x_threshold)
                    {
                        vel.linear.x = vel_x_threshold;
                    }
                    else if (vel.linear.x < -vel_x_threshold)
                    {
                        vel.linear.x = -vel_x_threshold;
                    }

                    if (vel.linear.y > vel_y_threshold)
                    {
                        vel.linear.y = vel_y_threshold;
                    }
                    else if (vel.linear.y < -vel_y_threshold)
                    {
                        vel.linear.y = -vel_y_threshold;
                    }
                }
            }
            else
            {
                vel.linear.x = 0;
                vel.linear.y = 0;
                vel.angular.z = det_z;

                //限幅
                if (vel.angular.z > vel_z_threshold)
                {
                    vel.angular.z = vel_z_threshold;
                }
                else if(vel.angular.z < -vel_z_threshold)
                {
                    vel.angular.z = -vel_z_threshold;
                }
            }
            //cout << "The velocity is " << vel.linear.x << " " << vel.linear.y << " " << vel.angular.z << endl;
            cmd_vel_pub.publish(vel);
        }

        ros::Rate Rate(10);
        Rate.sleep();
        ros::spinOnce();
    }
}


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
    ros::init(argc,argv,"new_robot_base_control");
    RobotBaseControl RobotBaseControl;                              //单位都是m
    RobotBaseControl.Run();                                         //如果 finish_flag = 1, 不断显示 Ready
    ros::spin();
    return 0;
}
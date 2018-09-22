//
// Created by robot2 on 18-9-19.
//

#include <std_msgs/String.h>
#include "robot_base_move.h"


RobotBaseMove::RobotBaseMove()
{
    odometry_sub = node.subscribe("odom", 50, &RobotBaseMove::OdometryCallBack, this);             //接收odom消息，转化为 cur_pose
    move_ser = node.advertiseService("base_move_service", &RobotBaseMove::MoveService, this);
    move_sub = node.subscribe("base_move_topic", 50, &RobotBaseMove::MoveCallBack, this);          //接收到目标点，转化为 tar_pose 
    move_state_pub = node.advertise<std_msgs::Bool>("base_move_state_topic", 10);                  //到达指定位置时，发 1 到 ”move_state_pub“
    cmd_vel_pub = node.advertise<geometry_msgs::Twist>("cmd_vel", 50);
}

RobotBaseMove::~RobotBaseMove()
{

}

void RobotBaseMove::Run()
{
    while (ros::ok())
    {
        if (move_flag)                                                               //move_flag = 1时运动， move_flag = 0 时停止
        {
            cout<<"Running"<<endl;
            double det_x, det_y, det_z;
            geometry_msgs::Twist vel;
            det_x = tar_pose.x - cur_pose.x;
            det_y = tar_pose.y - cur_pose.y;
            det_z = tar_pose.z - cur_pose.z;
            cout << det_x << " " << det_y << " " << det_z << endl;
            double det_x_local = det_x*cos(cur_pose.z) + det_y*sin(cur_pose.z);
            double det_y_local = -det_x*sin(cur_pose.z) + det_y*cos(cur_pose.z);

            if (abs(det_z) < 0.05)
            {
                if (abs(det_x) < 0.005 && abs(det_y) < 0.005)
                {
                    cout << "Robot get the goal" << endl;

                    move_flag = false;

                    std_msgs::Bool msg;
                    msg.data = 1;
                    move_state_pub.publish(msg);                                    //到达指定位置时，发 1 到 ”base_move_state_topic“
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
            cout << "The velocity is " << vel.linear.x << " " << vel.linear.y << " " << vel.angular.z << endl;
            cmd_vel_pub.publish(vel);
        }

        ros::Rate Rate(10);
        Rate.sleep();
        ros::spinOnce();
    }
}

void RobotBaseMove::OdometryCallBack(const nav_msgs::OdometryConstPtr msg)
{
    Ouaterniond2Euler(msg->pose.pose, cur_pose);
    //cout << cur_pose.x << " " << cur_pose.y << " " << cur_pose.z << endl;
}

void RobotBaseMove::MoveCallBack(move_base_msgs::MoveBaseGoal goal)
{
    cout<<"Get the goal"<<endl;
    Ouaterniond2Euler(goal.target_pose.pose, tar_pose);
    move_flag = true;
}


//TODO：这个service现在有问题，进去了这个while循环就收不到回调函数了
bool RobotBaseMove::MoveService(robot_base_move::base_moveRequest &req, robot_base_move::base_moveResponse &res)
{
    Ouaterniond2Euler(req.goal.target_pose.pose, tar_pose);

    while (1)
    {
        double det_x, det_y, det_z;
        geometry_msgs::Twist vel;
        det_x = tar_pose.x - cur_pose.x;
        det_y = tar_pose.y - cur_pose.y;
        det_z = tar_pose.z - cur_pose.z;
        cout << det_x << " " << det_y << " " << det_z << endl;
        double det_x_local = det_x*cos(cur_pose.z) + det_y*sin(cur_pose.z);
        double det_y_local = -det_x*sin(cur_pose.z) + det_y*cos(cur_pose.z);
        cout << "det_x_local = "<< det_x_local << "\ndet_y_local = "<< det_y_local;

        if (abs(det_z) < 0.02)
        {
            if (abs(det_x_local) < 0.005 && abs(det_y_local) < 0.005)
            {
                cout << "Robot get the goal" << endl;
                res.flag = 1;
                break;
            }
            else
            {
                vel.linear.x = det_x_local;
                vel.linear.y = det_y_local;

                //限幅
                if (vel.linear.x > vel_x_threshold)
                {
                    vel.linear.x = vel_x_threshold;
                } else if (vel.linear.x < -vel_x_threshold)
                {
                    vel.linear.x = -vel_x_threshold;
                }

                if (vel.linear.y > vel_y_threshold)
                {
                    vel.linear.y = vel_y_threshold;
                } else if (vel.linear.y < -vel_y_threshold)
                {
                    vel.linear.y = -vel_y_threshold;
                }
            }
        } else
        {
            vel.linear.x = 0;
            vel.linear.y = 0;
            vel.angular.z = det_z;

            //限幅
            if (vel.angular.z > vel_z_threshold)
            {
                vel.angular.z = vel_z_threshold;
            } else
            {
                vel.angular.z = -vel_z_threshold;
            }
        }
        //cout << "the velocity is " << vel.linear.x << " " << vel.linear.y << " " << vel.angular.z << endl;


        cmd_vel_pub.publish(vel);

        ros::Rate Rate(10);
        Rate.sleep();
        ros::spinOnce();
    }

    return true;
}

void RobotBaseMove::Ouaterniond2Euler(const geometry_msgs::Pose &quat_pose, BasePose &euler_pose)
{
    euler_pose.x = quat_pose.position.x;
    euler_pose.y = quat_pose.position.y;

    Eigen::Quaterniond q(quat_pose.orientation.x, quat_pose.orientation.y, quat_pose.orientation.z,
                         quat_pose.orientation.w);
    Eigen::Matrix3d Rx = q.toRotationMatrix();
    Eigen::Vector3d eular = Rx.eulerAngles(2, 1, 0);
    euler_pose.z = eular[2];
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "robot_base_move");
    RobotBaseMove RobotBaseMove;//单位都是m
    RobotBaseMove.Run();
    ros::spin();
    return 0;
}
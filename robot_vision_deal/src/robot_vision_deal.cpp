//
// Created by robot2 on 18-6-1.
//

#include "robot_vision_deal.h"

ros::Publisher pub1;
ros::Publisher pub2;

void cloud_cb1 (const sensor_msgs::ImageConstPtr& input)
{
    ROS_INFO("Camera_1 Open");
    // Create a container for the data.
    //sensor_msgs::PointCloud2 output;
    Mat Color =  cv_bridge::toCvCopy(input,sensor_msgs::image_encodings::TYPE_16UC1)->image;
    // Do data processing here...
    //output = *input;

    // Publish the data.
    //pub1.publish (output);
}

void cloud_cb2 (const sensor_msgs::ImageConstPtr& input)
{
    ROS_INFO("Camera_2 Open");
    // Create a container for the data.
    //sensor_msgs::PointCloud2 output;
    Mat Color =  cv_bridge::toCvCopy(input,sensor_msgs::image_encodings::TYPE_16UC1)->image;

    // Do data processing here...
    //output = *input;

    // Publish the data.
    //pub1.publish (output);
}


int main(int argc,char** argv)
{
    // Initialize ROS
    ros::init (argc, argv, "robot_vision_deal");
    ros::NodeHandle nh;


    ros::Subscriber sub1 = nh.subscribe ("/camera1/depth/image_raw", 1, cloud_cb1);
    ros::Subscriber sub2 = nh.subscribe ("/camera2/depth/image_raw", 1, cloud_cb2);
    pub1 = nh.advertise<sensor_msgs::PointCloud2> ("output1", 1);
    pub2 = nh.advertise<sensor_msgs::PointCloud2> ("output2", 1);

    // Spin
    ros::spin ();
}
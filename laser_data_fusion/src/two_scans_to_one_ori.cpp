#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "laser_geometry/laser_geometry.h"
#include <math.h>
#include <vector>
using namespace std;

#define pi 3.1415926

float vehicle_x = 0.352; //half x & half y
float vehicle_y = 0.334; //used for coordinate transform 

laser_geometry::LaserProjection projector;
sensor_msgs::PointCloud cloud1;
sensor_msgs::PointCloud cloud2;
sensor_msgs::LaserScan scan_pub;
//vector< vector<double> > ranges_v( 1440,vector<double>(0) );
vector<double> ranges_v[1440];

void scan_to_range1 (const sensor_msgs::LaserScan scan)
{
  projector.projectLaser(scan, cloud1);

  for ( int i = 0; i < cloud1.points.size(); i++)
  {
    //Change coordinate from laser to base_link
    // double x = cloud1.points[i].x;
    // double y = cloud1.points[i].y;
    double x = cloud1.points[i].x * 0.7071 + cloud1.points[i].y * 0.7071 + vehicle_x;
    double y = cloud1.points[i].y * 0.7071 - cloud1.points[i].x * 0.7071 + vehicle_y;
    
    //Calculate angle of the points 
    double point_theta = atan2(y,x) * 180 / pi;
    if (point_theta < 0)
    {
      point_theta = 360 + point_theta;
    }

    //Classification of points and get the ranges
    int j = floor(point_theta / 0.25);
    double L = sqrt(x*x + y*y);
    // ROS_INFO("%d",j);
    ranges_v[j].push_back(L); 
  } 
}

void scan_to_range2 (const sensor_msgs::LaserScan scan)
{
  projector.projectLaser(scan, cloud2);
  // int a = cloud2.points.size();
  // ROS_INFO("%d",a);
  for ( int i = 0; i < cloud2.points.size(); i++)
  {
    //Change coordinate from laser to base_link
    // double x = cloud2.points[i].x;
    // double y = cloud2.points[i].y;
    double x = -cloud2.points[i].x * 0.7071 - cloud2.points[i].y * 0.7071 - vehicle_x;
    double y = -cloud2.points[i].y * 0.7071 + cloud2.points[i].x * 0.7071 - vehicle_y;
    
    //Calculate angle of the points 
    double point_theta = atan2(y,x) * 180 / pi;
    if (point_theta < 0)
    {
      point_theta = 360 + point_theta;
    }

    //Classification of points and get the ranges
    int j = floor(point_theta / 0.25);
    double L = sqrt(x*x + y*y);
    ranges_v[j].push_back(L);     
  } 
}


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "two_scans_to_one");
  ros::NodeHandle n;
  ros::Subscriber sub1 = n.subscribe("/laser_scan1", 1, scan_to_range1);
  ros::Subscriber sub2 = n.subscribe("/laser_scan2", 1, scan_to_range2);
  
  ros::Publisher pub = n.advertise<sensor_msgs::LaserScan>("/scan", 1000);
  ros::Rate loop_rate(10);

  while(ros::ok())
  {
    //Calculate average ranges and send to scan message
    scan_pub.ranges.resize(1440);  
    double sum;
    for(int i = 0; i < 1440; i++)  
    { 
   // int a = ranges_v[i].size();
   // ROS_INFO("%d",i);
   // ROS_INFO("%d",a);
    if(ranges_v[i].size()>0)
    {
     sum = 0;
     for(int j = 0; j < ranges_v[i].size(); j++)
      {
      sum += ranges_v[i][j];
      }
     double ranges_average = sum / ranges_v[i].size();
  // ROS_INFO("%f",ranges_average);
     scan_pub.ranges[i] = ranges_average;
    }   
    ranges_v[i].clear();
    }
    

   //Populate the scan message
    ros::Time scan_time = ros::Time::now();
    scan_pub.header.stamp = scan_time;
    scan_pub.header.frame_id = "laser";
    scan_pub.angle_min = 0;
    scan_pub.angle_max = 2*pi;
    scan_pub.angle_increment = 0.25 * (pi/180);
    scan_pub.time_increment = 0.1 / 1440;
    scan_pub.range_min = 0.0;
    scan_pub.range_max = 10.0;

    pub.publish(scan_pub);
    ros::spinOnce();
    for(int i = 0; i < 1440; i++)  
    {  
      scan_pub.ranges[i] = 0;
    }  
    loop_rate.sleep();

  }
  return 0;
}
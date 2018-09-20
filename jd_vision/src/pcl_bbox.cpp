#include <iostream>
#include <sstream>
#include <map>

#include <Eigen/Geometry>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <ros/ros.h>
#include <ros/package.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/common/transforms.h>
#include <pcl/conversions.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <image_transport/image_transport.h>

#include <cv_bridge/cv_bridge.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

#include <jd_vision/Frame.h>
#include <jd_vision/RobotMsg.h>
#include <jd_vision/Command.h>
#include "jd_vision/config.h"
#include <pcl/filters/project_inliers.h>
#include <string>
#include <Eigen/Core> 
#include <boost/thread/thread.hpp>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>


using namespace std;

const float fx = 5.3559603642831371e+02;
const float fy = 5.3572146950583328e+02;
const float cx = 3.1746365476030900e+02;
const float cy = 2.3503066656877743e+02;

typedef pcl::PointCloud<pcl::PointXYZRGBNormal> PointCloudT;
typedef pcl::PointXYZRGBNormal PointT;

float c_z_1,c_z_2,c_z_3,c_z_4,c_z_5,c_z,c_x,c_x_2,c_x_3,c_x_4,c_x_5,c_x_1,c_y,c_y_1,c_y_2,c_y_3,c_y_4,c_y_5;
cv::Mat image_to_save;
cv::Mat depth_to_save;
std::vector<cv::Mat> mask_vec;
std::vector<int> classes;
vector<float> robot_pose;
vector<float> robot_joint;
float eh_theta;
vector<float> eh_axis;
vector<float> eh_translation;
Eigen::Affine3f trans_eye_hand;
//Eigen::Affine3f trans_world;






PointCloudT::Ptr range2PC(const cv::Mat& color,const cv::Mat& depth, const std::vector<float>& robot_pose_)
{
	vector<float> robot(6,0.0);
	robot[0] = robot_pose_[0];
	robot[1] = robot_pose_[1];
	robot[2] = robot_pose_[2];
	robot[3] = robot_pose_[3];
	robot[4] = robot_pose_[4];
	robot[5] = robot_pose_[5];

	Eigen::Affine3f trans_robot = Eigen::Affine3f::Identity();

	float theta_robot = sqrt(robot[3]*robot[3] + robot[4]*robot[4] + robot[5]*robot[5]);
	Eigen::Vector3f axis_robot;
	axis_robot << robot[3]/theta_robot,robot[4]/theta_robot,robot[5]/theta_robot;
	trans_robot.rotate (Eigen::AngleAxisf (theta_robot, axis_robot));
	trans_robot.translation() << robot[0], robot[1], robot[2];

		//---------------------get transform world---------------------------------
	Eigen::Affine3f trans_world =  trans_robot * trans_eye_hand;

	PointT ptrgbN;
		PointCloudT::Ptr pc(new PointCloudT);                             //采集的color按理说是跟深度图校正后的像素颜色（即深度图像素的rgb值）
		float over_f_x = 1.0 / fx;
		float over_f_y = 1.0 / fy;
		for (int i = 0; i < depth.rows; i++)
		{
			const ushort* data = depth.ptr<ushort>(i);
			const uchar* data_color = color.ptr<uchar>(i);
			for (int j = 0; j < depth.cols; j++)
			{
				Eigen::Vector3f point;
				point[2] = data[j] / Config::get<float>("DepthMapFactor");            //data 存放d深度值，data_color 存放rgb值
				point[0] = (j - cx) * point[2] * over_f_x;                            // j 是深度图中的像素，point[]:Z,X,Y点云三维坐标值
				point[1] = (i - cy) * point[2] * over_f_y;

				//if(point[2] > Config::get<float>("ins_dist")) continue;

				Eigen::Vector3f pointWorld = trans_world * point;
				ptrgbN.z = pointWorld[2];
				ptrgbN.x = pointWorld[0];
				ptrgbN.y = pointWorld[1];

				ptrgbN.b = data_color[3 * j];
				ptrgbN.g = data_color[3 * j + 1];
				ptrgbN.r = data_color[3 * j + 2];

				pc->push_back(ptrgbN);
			}
		}
		return pc;
	}




float pcl2bbox(PointCloudT::Ptr cloud)    //定义函数的方式对否?
{

	//pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBNormal>);
	//string fileName("1.pcd");

	//cloud = p_write2;   //????? or p_write=*cloud???

	//pcl::io::loadPCDFile(fileName,*cloud);
	// pcl::io::savePCDFile("temp.pcd",*cloud_save);
	// PointCloudT::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBNormal>);
	// std::cout<<"1"<<endl;

	// string fileName("temp.pcd");
	// pcl::io::loadPCDFile(fileName,*cloud);
	// std::cout<<"1"<<endl;

	pcl::visualization::PCLVisualizer viewer;
	pcl::NormalEstimationOMP<pcl::PointXYZRGBNormal,pcl::PointXYZRGBNormal> nor;

	pcl::search::KdTree<pcl::PointXYZRGBNormal>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGBNormal>);
	nor.setSearchMethod(tree);
	nor.setInputCloud(cloud);
	nor.setNumberOfThreads(10);
	nor.setRadiusSearch(0.03);
	nor.compute(*cloud);


	size_t cloud_size = cloud->size();
	for (size_t i = 0;i<cloud_size;++i)
	{
		uint8_t r = (cloud->at(i).normal_x + 1)/2 * 255;
		uint8_t g = (cloud->at(i).normal_y + 1)/2 * 255;
		uint8_t b = (cloud->at(i).normal_z + 1)/2 * 255;

		uint32_t rgb = ((uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b);
		cloud->at(i).rgb = *reinterpret_cast<float*>(&rgb);
	}


	Eigen::Vector4f pcaCentroid;
	pcl::compute3DCentroid(*cloud,pcaCentroid);

	pcl::PointXYZRGBNormal mincPoint,maxcPoint;
	pcl::getMinMax3D(*cloud,mincPoint,maxcPoint);

	float p_x=pcaCentroid[0];
	float p_y=pcaCentroid[1];
	float p_z=maxcPoint.z;
	std::cout<< "cx="<<p_x<<" , "<<"cy="<<p_y<<"maxz="<<p_z<<endl;

	Eigen::Matrix3f covariance;
	pcl::computeCovarianceMatrixNormalized(*cloud,pcaCentroid,covariance);
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix3f> eigen_solver(covariance,Eigen::ComputeEigenvectors);
	Eigen::Matrix3f eigenVectorsPCA = eigen_solver.eigenvectors();
	eigenVectorsPCA.col(2) = eigenVectorsPCA.col(0).cross(eigenVectorsPCA.col(1));

	// Transform the original cloud to the origin where the principal components correspond to the axes.
	Eigen::Matrix4f transform(Eigen::Matrix4f::Identity());
	transform.block<3,3>(0,0) = eigenVectorsPCA.transpose();
	transform.block<3,1>(0,3) = -1.f * (transform.block<3,3>(0,0) * pcaCentroid.head<3>());

	pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr transformedCloud(new pcl::PointCloud<pcl::PointXYZRGBNormal>);
	pcl::transformPointCloudWithNormals(*cloud,*transformedCloud,transform);

	pcl::PointXYZRGBNormal minPoint,maxPoint;
	pcl::getMinMax3D(*transformedCloud,minPoint,maxPoint);                                                   //minpoint.x,minpoint.y,minpoint.z代表最小值,其余同理
	const Eigen::Vector3f meanDiagonal = 0.5f*(maxPoint.getVector3fMap() + minPoint.getVector3fMap());


	const Eigen::Quaternionf bboxQuaternion(eigenVectorsPCA); //Quaternions are a way to do rotations https://www.youtube.com/watch?v=mHVwd8gYLnI
	const Eigen::Vector3f bboxTransform = eigenVectorsPCA * meanDiagonal + pcaCentroid.head<3>();

	//d::cout<< pcaCentroid.head<3><<endl;

	viewer.addPointCloud<pcl::PointXYZRGBNormal>(cloud);
	viewer.addCube(bboxTransform, bboxQuaternion, maxPoint.x - minPoint.x, maxPoint.y - minPoint.y, maxPoint.z - minPoint.z, "bbox");
	viewer.setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION,pcl::visualization::PCL_VISUALIZER_REPRESENTATION_WIREFRAME,"bbox");

	while(!viewer.wasStopped())
	{
		viewer.spinOnce(100);
		boost::this_thread::sleep (boost::posix_time::microseconds (100000));
	}

  return p_x, p_y, p_z; // 右手坐标系!!!
}


//回调函数

void chatterCallback(const jd_vision::Frame& fr)
{
	std::cout<<"cb function is called"<<endl;
	classes.clear();
	for (int i=0;i<fr.categories.size();i++)
	{
		cv_bridge::CvImagePtr img_ptr_res;
		try{
			std::cout<<"img_ptr_res"<<endl;
			img_ptr_res = cv_bridge::toCvCopy(fr.masks[i], sensor_msgs::image_encodings::TYPE_16UC1);
		}
		catch (cv_bridge::Exception& e)
		{
			ROS_ERROR("cv_bridge exception1:  %s", e.what());
			return;
		}
		mask_vec.push_back(img_ptr_res->image.clone());
	}
	//std::cout<<mask_vec[0]<<endl;

	cv_bridge::CvImagePtr img_ptr_color;
	try{
		std::cout<<"img_ptr_color"<<endl;
		 img_ptr_color = cv_bridge::toCvCopy(fr.color, sensor_msgs::image_encodings::BGR8); //BGR8
		}
		catch (cv_bridge::Exception& e)
		{
			ROS_ERROR("cv_bridge exception2:  %s", e.what());
			return;
		}
		image_to_save = img_ptr_color->image.clone();

		cv_bridge::CvImagePtr img_ptr_dph;
		try{
			std::cout<<"img_ptr_dph"<<endl;
			img_ptr_dph = cv_bridge::toCvCopy(fr.depth, sensor_msgs::image_encodings::TYPE_16UC1);
		}
		catch (cv_bridge::Exception& e)
		{
			ROS_ERROR("cv_bridge exception3:  %s", e.what());
			return;
		}
		depth_to_save = img_ptr_dph->image.clone();

		for (int i=0;i<fr.categories.size();i++)
		{
			std::cout<<"categories"<< fr.categories.size() << "and now" << i <<endl;
			classes.push_back(fr.categories[i]);
		}

		std::cout<<"robot_pose"<<endl;

		robot_pose[0] = fr.robot_pose[0];
		robot_pose[1] = fr.robot_pose[1];
		robot_pose[2] = fr.robot_pose[2];
		robot_pose[3] = fr.robot_pose[3];
		robot_pose[4] = fr.robot_pose[4];
		robot_pose[5] = fr.robot_pose[5];

		std::cout<<robot_pose[0]<<endl;
		std::cout<<"robot_joint"<<endl;

		robot_joint[0] = fr.robot_joint[0];
		robot_joint[1] = fr.robot_joint[1];
		robot_joint[2] = fr.robot_joint[2];
		robot_joint[3] = fr.robot_joint[3];
		robot_joint[4] = fr.robot_joint[4];
		robot_joint[5] = fr.robot_joint[5];

		PointCloudT::Ptr cloud_filtered1(new PointCloudT);
		PointCloudT::Ptr cloud_filtered2(new PointCloudT);

		std::cout<<classes.size()<<endl;
		std::cout<<classes[0]<<endl;

		c_y_1=-9999.0;                                          // 先定义
    	c_y_2=-9999.0;                                          // 先定义
   		c_y_3=-9999.0;                                          // 先定义
   		c_y_4=-9999.0;                                          // 先定义
    	c_y_5=-9999.0;                                          // 先定义

  for (int i=0;i<classes.size();i++)  //  N是指的订阅消息传来的不同商品个数
  {
        if (classes[i]==16) //classes[i]
        {
            //cv::Mat roi=depth_to_save;
            //cv::Mat temp_depth;  //深度图 cv::Mat temp_depth(roi.rows,roi.cols,roi.depth(),Scalar())

            //cv::Mat roi=depth_to_save(cv::Rect(0,0,mask_vec[i].cols,mask_vec[i].rows));
            //cv::Mat mask=mask_vec[i].clone();
            //mask_vec[i].copyTo(roi,mask);

        	for(int j=0;j<mask_vec[i].rows;j++)
        		for(int k=0;k<mask_vec[i].cols;k++)
        		{
        			if(mask_vec[i].at<int>(j,k)==0)
        			{
        				depth_to_save.at<float>(j,k)=0.0;
        			}
        		}

        		//std::cout<<depth_to_save<<endl;

        		PointCloudT::Ptr p_c(new pcl::PointCloud<pcl::PointXYZRGBNormal>);

				p_c = range2PC(image_to_save,depth_to_save,robot_pose);   //处理后的点云图, trans_world订阅可得
				//std::cout<<p_c<<endl;
				std::cout<<"range2PC finished"<<endl;

				std::cout<<"cloud number"<<p_c->size()<<std::endl;

				   pcl::VoxelGrid<pcl::PointXYZRGBNormal> filter;
				    filter.setInputCloud(p_c);
				    filter.setLeafSize(0.01f, 0.01f, 0.01f);
    				filter.filter(*cloud_filtered1);

					//直通滤波,去掉z方向上背景与前景分离
					//             pcl::PassThrough<pcl::PointXYZRGBNormal> pass; //创建滤波器对象
					//             pass.setInputCloud (p_c);                      //设置待滤波的点云
					//             pass.setFilterFieldName ("z");                 //设置在Z轴方向上进行滤波,即将点云中所有点的Z轴坐标不在该范围内的点过滤掉或保留，这里是过滤掉
					//             pass.setFilterLimits (0.0, 1.0);               //设置滤波范围为0~1,在范围之外的点会被剪除
					//             //pass.setFilterLimitsNegative (true);         //设置保留范围内还是过滤掉范围内
					//             pass.filter (*cloud_filtered1);                //存储
					// std::cout<<cloud_filtered1<<endl;


					            //统计滤波,去掉噪声点
				    pcl::StatisticalOutlierRemoval<pcl::PointXYZRGBNormal> sor;    //创建滤波器对象
		            sor.setInputCloud (cloud_filtered1);                           //设置待滤波的点云
		            sor.setMeanK (50);                                             //设置在进行统计时考虑查询点临近点数
		            sor.setStddevMulThresh (1);                                  //设置判断是否为离群点的阀值
		            sor.filter (*cloud_filtered2);                                 //存储
					std::cout<<cloud_filtered2<<endl;


            float c_x,c_y,c_z=pcl2bbox(cloud_filtered2);  //先定义三个一维数组 c_x ...
            std::cout<<"The (cx,cy,hz) is "<< c_x<<" "<< c_y<<" "<< c_z<<" "<<endl;
            if (c_y>c_y_1)
            {
                c_x_1=c_x;c_z_1=c_z;c_y_1=c_y;  //选取距离机器人最近的一组点云,并把最近一组点云的上表面坐标(c_x_1,c_y_1,c_z_1)输出

            }
        }

        //此处可继续添加其他类别物体

    }
    std::cout<<"The (cx,cy,hz) is "<< c_x_1<<" "<< c_y_1 <<" "<< c_z_1 <<" "<<endl;

}



int main (int argc, char** argv)
{

	std::string pkg_loc = ros::package::getPath("jd_vision");
	Config::setParameterFile(pkg_loc + "/parameter.yml");

	eh_translation = Config::get<vector<float> >("eh_translation");
	eh_axis = Config::get<vector<float> >("eh_axis");
	eh_theta = Config::get<float>("eh_theta");

	trans_eye_hand = Eigen::Affine3f::Identity();
	Eigen::Vector3f axis_eye_hand;
	axis_eye_hand << eh_axis[0],eh_axis[1],eh_axis[2];
	trans_eye_hand.rotate (Eigen::AngleAxisf (eh_theta, axis_eye_hand));
	trans_eye_hand.translation() << eh_translation[0]/1000.0, eh_translation[1]/1000.0, eh_translation[2]/1000.0;
	robot_pose  = vector<float>(6,0.0);
	robot_joint = vector<float>(6,0.0);




	ros::init(argc, argv, "listener");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe( "frame", 1000, chatterCallback); // 订阅message消息

	//订阅彩色图,深度图,机器人姿态,以及所需抓取物体的淹没和类别
	//并对得到的点云处理得到bbox,最终返回离得近的那一个bbox的坐标


	//ros::init(argc, argv, "talker");
	//ros::Publisher command = n.advertise<std_msgs::Float32MultiArray>("command_pub", 1000);
	//std_msgs::Float32MultiArray m;
	//m.data[]=??
	//command.publish(m);
	while(ros::ok())
	{
		ros::spin();
	}

	//遍历所有订阅的消息后,最后返回要抓取的点云的坐标.
	return 0;
}

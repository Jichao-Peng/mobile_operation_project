#ifndef OBJECT_H_
#define OBJECT_H_

#include <opencv2/opencv.hpp>

#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>

typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloudT;
typedef pcl::PointXYZRGB PointT;

using std::vector;
using std::cout;
using std::endl;

namespace eh_system{
	class Object
	{
	public:
		int id;
		PointCloudT::Ptr pc_ptr;
		cv::Point3f centre;
	
		Object(const Object& obj);
		Object(PointCloudT::Ptr pc,int id);
		
		void add(const Object& o);
		void addPose(const cv::Mat& m);

		Object& operator=(const Object& other);
		//Object operator+=(const Object& o);
	};
}

#endif
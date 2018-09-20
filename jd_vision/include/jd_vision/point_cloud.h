#ifndef POINT_CLOUD_H_
#define POINT_CLOUD_H_

#include <opencv2/opencv.hpp>

#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/features/normal_3d.h>  
#include <pcl/features/normal_3d_omp.h>
#include <pcl/kdtree/kdtree.h>

typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloudT;
typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<pcl::Normal> PointCloudN;

namespace eh_system
{
	class PointCloud
	{
	protected:
		cv::Mat pc_mat;
		PointCloudT::Ptr pc_ptr;
		int num;
		cv::Point3f center_g;

		PointCloudT Mat2PC(const cv::Mat& pc_mat);
		cv::Mat PC2Mat(const PointCloudT& cloud);

	public:
		PointCloud(){};

		PointCloud(const PointCloud& pc_obj);

		PointCloud& operator = (const PointCloud& pc_obj);

		PointCloud(const cv::Mat& pc_mat);

		PointCloud(const PointCloudT& pc);

		int getNum() const
		{
			return num;
		};

		cv::Mat getMat() const
		{
			return pc_mat.clone();
		};

		PointCloudT::Ptr getPCPtr() const
		{
			PointCloudT::Ptr res(new PointCloudT(*pc_ptr));
			return res;
		}

		cv::Point3f getCG() const
		{
			return center_g;
		}
		
		virtual void scalePointCloud(const float& s);
		virtual void viewPC();
	};

	class PointCloudNorm:public PointCloud
	{
	private:
		cv::Mat pc_norm_mat;
		PointCloudN::Ptr pc_norm_ptr;
		void computeNormals(PointCloudT::Ptr inputCloud,pcl::PointCloud<pcl::Normal>& normals,const cv::Point3f& viewpoint);
		cv::Mat PC2Mat_WithNorm(const PointCloudT& cloud,const PointCloudN& normals);

	public:
		PointCloudNorm(){};
		PointCloudNorm(const cv::Mat& pc_mat);
		PointCloudNorm(const PointCloudT& pc);
		cv::Mat getMatNorm() const
		{
			return pc_norm_mat.clone();
		};

		PointCloudN::Ptr getNormPtr() const
		{
			PointCloudN::Ptr res(new PointCloudN(*pc_norm_ptr));
			return res;
		}
		virtual void scalePointCloud(const float& s);
		//virtual void viewPC();
	};
}

#endif

#include "opencv_bridge/point_cloud.h"

namespace eh_system{

	PointCloud::PointCloud(const cv::Mat& pc_mat):pc_mat(pc_mat)
	{
		CV_Assert(pc_mat.cols == 3 || pc_mat.cols == 6);
		PointCloudT pc = Mat2PC(pc_mat);
		num = pc_mat.rows;
		center_g = cv::Point3f(0,0,0);
		for(int i = 0;i < num; i++)
		{
			const float* data = pc_mat.ptr<float>(i);
			center_g.x += data[0];
			center_g.y += data[1];
			center_g.z += data[2];
		}
		center_g.x /= num;
		center_g.y /= num;
		center_g.z /= num;
		pc_ptr = PointCloudT::Ptr(new PointCloudT(pc));
	};

	PointCloud::PointCloud(const PointCloudT& pc)
	{
		pc_mat = PC2Mat(pc);
		num = pc_mat.rows;
		center_g = cv::Point3f(0,0,0);
		for(int i = 0;i < num; i++)
		{
			float* data = pc_mat.ptr<float>(i);
			center_g.x += data[0];
			center_g.y += data[1];
			center_g.z += data[2];
		}
		center_g.x /= num;
		center_g.y /= num;
		center_g.z /= num;
		pc_ptr = PointCloudT::Ptr(new PointCloudT(pc));
	};

	////copy constructor
	PointCloud::PointCloud(const PointCloud& pc_obj)
	{
		pc_mat = pc_obj.pc_mat.clone();
		pc_ptr = PointCloudT::Ptr(new PointCloudT(*(pc_obj.pc_ptr)));
		num = pc_obj.num;
		center_g = pc_obj.center_g;
	};

	////assign overload
	PointCloud& PointCloud::operator = (const PointCloud& pc_obj)
	{
		if(this != &pc_obj)
		{
			pc_mat = pc_obj.pc_mat.clone();
			pc_ptr = PointCloudT::Ptr(new PointCloudT(*(pc_obj.pc_ptr)));
			num = pc_obj.num;
			center_g = pc_obj.center_g;
		}
		return *this;
	}

	PointCloudT PointCloud::Mat2PC(const cv::Mat& pc_mat)
	{
		PointT ptrgbN;
		PointCloudT pc;
		for (int i = 0; i < pc_mat.rows;i++)
		{
			const float *data = pc_mat.ptr<float>(i);
			ptrgbN.x = data[0];
			ptrgbN.y = data[1];
			ptrgbN.z = data[2];
			pc.push_back(ptrgbN);
		}
		return pc;
	};

	cv::Mat PointCloud::PC2Mat(const PointCloudT& cloud)
	{
		cv::Mat PC(cloud.size(),3,CV_32FC1);
		for(int i= 0;i < cloud.size();i++)
		{
			float* data = PC.ptr<float>(i);
			data[0] = cloud.points[i].x;
			data[1] = cloud.points[i].y;
			data[2] = cloud.points[i].z;
		}
		return PC.clone();
	};

	void PointCloud::scalePointCloud(const float& s)
	{
		for(int i = 0; i < num; i++)
		{
			float* data_pc = pc_mat.ptr<float>(i);
			data_pc[0] *= s;
			data_pc[1] *= s;
			data_pc[2] *= s;
			pc_ptr->points[i].x *= s;
			pc_ptr->points[i].y *= s;
			pc_ptr->points[i].z *= s;
		}
		center_g.x *= s;
		center_g.y *= s;
		center_g.z *= s;
	};

	void PointCloud::viewPC()
	{
	    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("Viewer"));
	    viewer->setBackgroundColor(0, 0, 0);   
	     pcl::visualization::PointCloudColorHandlerCustom<PointT> cloud_in_color_h (pc_ptr, (int) 255 , (int) 255 ,
	        (int) 255);
	    viewer->addPointCloud(pc_ptr, cloud_in_color_h, "a");
	    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1.5, "a");
	    viewer->setCameraPosition(0,0,-1,0,0,1,0,-1,0);
	    viewer->addCoordinateSystem(1.0);

	    while (!viewer->wasStopped())
	        viewer->spinOnce();
	};
//--------------------------------------------------------------------------------------------------

	PointCloudNorm::PointCloudNorm(const cv::Mat& pc_mat):PointCloud(pc_mat)
	{
		PointCloudN normals;
		computeNormals(pc_ptr,normals,center_g);
		pc_norm_mat = PC2Mat_WithNorm(*pc_ptr,normals);
		pc_norm_ptr = PointCloudN::Ptr(new PointCloudN(normals));
	}

	PointCloudNorm::PointCloudNorm(const PointCloudT& pc):PointCloud(pc)
	{
		PointCloudN normals;
		computeNormals(pc_ptr,normals,center_g);
		pc_norm_mat = PC2Mat_WithNorm(*pc_ptr,normals);
		pc_norm_ptr = PointCloudN::Ptr(new PointCloudN(normals));

		// pc_mat = PC2Mat(pc);
		// num = pc_mat.rows;
		// center_g = cv::Point3f(0,0,0);
		// for(int i = 0;i < num; i++)
		// {
		// 	float* data = pc_mat.ptr<float>(i);
		// 	center_g.x += data[0];
		// 	center_g.y += data[1];
		// 	center_g.z += data[2];
		// }
		// center_g.x /= num;
		// center_g.y /= num;
		// center_g.z /= num;
		// pc_ptr = PointCloudT::Ptr(new PointCloudT(pc));
		
		// PointCloudN normals;
		// computeNormals(pc_ptr,normals,center_g);
		// pc_norm_mat = PC2Mat_WithNorm(*pc_ptr,normals);
		// pc_norm_ptr = PointCloudN::Ptr(new PointCloudN(normals));
	}

	cv::Mat PointCloudNorm::PC2Mat_WithNorm(const PointCloudT& cloud,const PointCloudN& normals)
	{
		cv::Mat PC(cloud.size(),6,CV_32FC1);
		for(int i= 0;i < cloud.size();i++)
		{
			float* data = PC.ptr<float>(i);
			data[0] = cloud.points[i].x;
			data[1] = cloud.points[i].y;
			data[2] = cloud.points[i].z;
			data[3] = normals.points[i].normal_x;
			data[4] = normals.points[i].normal_y;
			data[5] = normals.points[i].normal_z;
		}
		return PC.clone();
	}

	void PointCloudNorm::computeNormals(PointCloudT::Ptr inputCloud,pcl::PointCloud<pcl::Normal>& normals,const cv::Point3f& viewpoint)
	{
		pcl::NormalEstimationOMP<PointT, pcl::Normal> ne;
		pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT> ());
		ne.setInputCloud (inputCloud);
		ne.setSearchMethod (tree);
		ne.setKSearch(100); 
		ne.setViewPoint(viewpoint.x,viewpoint.y,viewpoint.z);
		ne.compute (normals);
	}

	void PointCloudNorm::scalePointCloud(const float& s)
	{
		for(int i = 0; i < num; i++)
		{
			float* data_pc = pc_mat.ptr<float>(i);
			float* data_pc_norm = pc_norm_mat.ptr<float>(i);
			data_pc[0] *= s;
			data_pc[1] *= s;
			data_pc[2] *= s;
			data_pc_norm[0] *= s;
			data_pc_norm[1] *= s;
			data_pc_norm[2] *= s;
			pc_ptr->points[i].x *= s;
			pc_ptr->points[i].y *= s;
			pc_ptr->points[i].z *= s;
		}
		center_g.x *= s;
		center_g.y *= s;
		center_g.z *= s;
	};
}
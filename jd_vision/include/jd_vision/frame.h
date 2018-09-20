#ifndef FRAME_H_
#define FRAME_H_

#include <Eigen/Geometry>

#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>
#include <algorithm>

#include "config.h"
#include "object.h"

#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>

using std::cout;
using std::endl;

namespace eh_system
{
	struct  MaskStruct
	{
		cv::Mat mask;
		int id;
		MaskStruct(const cv::Mat& m,const int& i):
		mask(m),id(i){};
	};

	void downSample(PointCloudT& inputCloud,const float& leafsize);

	void removeOut(PointCloudT& inputCloud,const float& mean_k,const float& std_mul_thres);

	void conditionFilter(PointCloudT::Ptr in_out_ptr,float z_thres);

	class Frame
	{
	private:
		const cv::Mat depth;
		const cv::Mat fcn_vec;
		const vector<float> robot_pose;		//1*6 vec

		static float fx;
		static float fy;
		static float cx;
		static float cy;

		static int contour_size;
		static int area_size;
		static float leaf_size;
		static float mean_k;
		static float std_mul_thres;

		Eigen::Affine3f trans_world;

		//vector to store masks for multiple instances
		std::vector<MaskStruct> mask_instance;

		int getArgMax(const float* data_row,int num);
		void maskProcess(cv::Mat& mask,int id);

	public:
		//objects in this frame
		std::vector<Object> object_vec;

		Frame();
		Frame(const Frame& f);
		Frame operator = (const Frame& f);
		Frame(const cv::Mat& d,const cv::Mat& fcn,const vector<float>& robot,
				const vector<float>& eye_hand_trans,const vector<float>& eye_hand_axis,
				const float& theta);

		//get object with single instance
		void getObject();

		// get objecr with multiple instances
		void getObjectMul();

		static void initPara();
	};
}

#endif
#ifndef PS_MACHINERY_H_
#define PS_MACHINERY_H_

#include <iostream>
#include <sstream> 
#include <map>

#include <pcl/filters/voxel_grid.h>
#include <pcl/registration/icp.h>
#include <pcl/filters/statistical_outlier_removal.h>

#include <opencv2/opencv.hpp>

#include "point_cloud.h"

#include <PPF/ppf_helpers.hpp>
#include <PPF/ppf_match_3d.hpp>

using std::vector;
using std::cout;
using std::endl;
using namespace cv::ppf_match_3d;

namespace eh_system{

	const double EPS = 1e-4;

	PointCloudT readPLY(const char* file_name,bool with_color);

	void writePLY(const char* file_name,PointCloudT::Ptr pc_ptr);

	//point cloud viewer:for debug
	void viewPC(PointCloudT::Ptr pc_view,std::string window_name);

	bool icpPCL(PointCloudT::Ptr pc_source, 
		PointCloudT::Ptr pc_target,int num_iter,cv::Mat& transMatrix,float* max_corr_dist,
		float corres_thres = 0.01);

	void sortEigenValue(cv::Mat& eValues,cv::Mat& eVectors,const cv::Mat& pc_trans_mat_centered);

	PointCloudT::Ptr poseEstimationPCA(const eh_system::PointCloud& scene,const eh_system::PointCloud& model,cv::Mat& result);

	void poseEstimationPPF(cv::ppf_match_3d::PPF3DDetector *detector,const eh_system::PointCloudNorm& scene,const eh_system::PointCloudNorm& model,cv::Mat& result);

	void Vec2Matrix(vector<float>& pose,  cv::Mat& poseMatrix);

	void Matrix2Vec(cv::Mat& poseMatrix, vector<float>& poseVec);
	
	struct ObjState{
	    cv::Mat pose;
	    bool picked;
	    ObjState(cv::Mat pose_):pose(pose_.clone()){
	      picked = false;
	    };
	    ObjState(const ObjState& other){
	      pose = other.pose.clone();
	      picked = other.picked;
	    };
	};


}

#endif
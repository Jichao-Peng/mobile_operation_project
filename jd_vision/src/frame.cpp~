#include "jd_vision/frame.h"

float eh_system::Frame::fx = 0;
float eh_system::Frame::fy = 0;
float eh_system::Frame::cx = 0;
float eh_system::Frame::cy = 0;
int eh_system::Frame::contour_size = 0;
int eh_system::Frame::area_size = 0 ;
float eh_system::Frame::leaf_size = 0;
float eh_system::Frame::mean_k = 0;
float eh_system::Frame::std_mul_thres = 0;

void eh_system::downSample(PointCloudT& input_cloud,const float& leafsize)
{
    PointCloudT res;
    pcl::VoxelGrid<pcl::PointXYZRGB > sor;
    sor.setInputCloud (PointCloudT::Ptr(new PointCloudT(input_cloud)));
    sor.setLeafSize (leafsize, leafsize, leafsize);
    sor.filter (input_cloud);
};

void eh_system::removeOut(PointCloudT& input_cloud,const float& mean_k,const float& std_mul_thres)
{
	pcl::StatisticalOutlierRemoval<PointT> sor;
	sor.setInputCloud (PointCloudT::Ptr(new PointCloudT(input_cloud)));
	sor.setMeanK(mean_k);
	sor.setStddevMulThresh(std_mul_thres);
	sor.filter(input_cloud);
};

void eh_system::conditionFilter(PointCloudT::Ptr in_out_ptr,float z_thres)
{
	 cout << "number after conditional filtering: " << in_out_ptr->size() << endl;
	 PointCloudT temp;
	 for(int i = 0; i < in_out_ptr->size(); i++){
	 	if(in_out_ptr->points[i].z < z_thres )
	 		continue;
	 	PointT p;
	 	p.x = in_out_ptr->points[i].x;
	 	p.y = in_out_ptr->points[i].y;
	 	p.z = in_out_ptr->points[i].z;
	 	temp.push_back(p);
	 }
	 *in_out_ptr = temp;
	// pcl::ConditionAnd<PointT>::Ptr range_cond (new pcl::ConditionAnd<PointT> ());
	// range_cond->addComparison (pcl::FieldComparison<PointT>::ConstPtr (new
	// pcl::FieldComparison<PointT> ("z", pcl::ComparisonOps::GT, -0.01)));
	// range_cond->addComparison (pcl::FieldComparison<PointT>::ConstPtr (new
	// pcl::FieldComparison<PointT> ("z", pcl::ComparisonOps::LT, 0.8)));

	// // build the filter
	// pcl::ConditionalRemoval<PointT> condrem;
	// condrem.setCondition (range_cond);
	// PointCloudT::Ptr t_temp (new PointCloudT(input_cloud));
	// condrem.setInputCloud (t_temp);
	// condrem.setKeepOrganized(true);
	// // apply filter
	// condrem.filter (out_cloud);
}


eh_system::Frame::Frame()
{
};

eh_system::Frame::Frame(const Frame& f):
depth(f.depth.clone()),fcn_vec(f.fcn_vec.clone()),robot_pose(f.robot_pose)
{
	if(this != &f)
	{
		trans_world = f.trans_world;
		object_vec = f.object_vec;
	}
}

void eh_system::Frame::initPara()
{
	fx = Config::get<float>("fx");
	fy = Config::get<float>("fy");
	cx = Config::get<float>("cx");
	cy = Config::get<float>("cy");
	contour_size = Config::get<int>("contour_size");
	area_size = Config::get<int>("area_size");
	leaf_size = Config::get<float>("leaf_size");
	mean_k = Config::get<float>("mean_k");
	std_mul_thres = Config::get<float>("std_mul_thres");
}

////Frame constructor
/// @param  d					depth image
/// @param  fcn 				fcn result matrix  n_pixel * n_class
/// @param  robot       		robot pose
/// @param  eye_hand_trans      translation part for eye-hand transformation
/// @param  eye_hand_axis       rotation axis for eye-hand transformation
eh_system::Frame::Frame(const cv::Mat& d,
							const cv::Mat& fcn,
							const vector<float>& robot,
							const vector<float>& eye_hand_trans,
							const vector<float>& eye_hand_axis,
							const float& theta):
		depth(d),fcn_vec(fcn),robot_pose(robot)
{
	// cout << eh_system::Frame::fx << endl;
	// cout << eh_system::Frame::fy << endl;
	// cout << eh_system::Frame::cx << endl;
	// cout << eh_system::Frame::cy << endl;
	//---------------------convert robot pose--------------------------------
	Eigen::Affine3f trans_robot = Eigen::Affine3f::Identity();

	float theta_robot = sqrt(robot[3]*robot[3] + robot[4]*robot[4] + robot[5]*robot[5]);
	Eigen::Vector3f axis_robot;
	axis_robot << robot[3]/theta_robot,robot[4]/theta_robot,robot[5]/theta_robot;
	trans_robot.rotate (Eigen::AngleAxisf (theta_robot, axis_robot));

	trans_robot.translation() << robot[0], robot[1], robot[2];

	//---------------------convert eyehand pose--------------------------------
	Eigen::Affine3f trans_eye_hand = Eigen::Affine3f::Identity();
	Eigen::Vector3f axis_eye_hand;
	axis_eye_hand << eye_hand_axis[0],eye_hand_axis[1],eye_hand_axis[2];
	trans_eye_hand.rotate (Eigen::AngleAxisf (theta, axis_eye_hand));
	trans_eye_hand.translation() << eye_hand_trans[0]/1000.0, eye_hand_trans[1]/1000.0, eye_hand_trans[2]/1000.0;

	//---------------------get transform world---------------------------------
	trans_world =  trans_robot * trans_eye_hand;
};

void eh_system::Frame::getObject()
{
	cout << "getting object..." << endl;
	std::vector<cv::Mat> mask_vec(4,cv::Mat());
	std::vector<bool> obj_exist(4,false); //index equals object ID

//------------------get mask for all kinds of objects-------------------------------
	for(int i = 0; i < fcn_vec.rows; i++)
	{  //fcn_vec is a n_pixel * n_class matrix
    	const float* data_r = fcn_vec.ptr<float>(i);
		int argMax = getArgMax(data_r,5);
			if(argMax == 0){
				if(obj_exist[0]){
					mask_vec[0].data[i] = 255;
				}
				else{
					mask_vec[0] = cv::Mat::zeros(depth.size(),CV_8UC1);
					obj_exist[0] = true;
				}
    		}
    		else if(argMax == 1){
				if(obj_exist[1]){
					mask_vec[1].data[i] = 255;
				}
				else{
					mask_vec[1] = cv::Mat::zeros(depth.size(),CV_8UC1);
					obj_exist[1] = true;
				}
    		}
    		// else if(argMax == 2){    //background

    		// }
    		else if(argMax == 3){  
				if(obj_exist[2]){
					mask_vec[2].data[i] = 255;
				}
				else{
					mask_vec[2] = cv::Mat::zeros(depth.size(),CV_8UC1);
					obj_exist[2] = true;
				}
    		}
    		else if(argMax == 4){
				if(obj_exist[3]){
					mask_vec[3].data[i] = 255;
				}
				else{
					mask_vec[3] = cv::Mat::zeros(depth.size(),CV_8UC1);
					obj_exist[3] = true;
				}
    		}
    }
    //cout << "world\n" << trans_world.matrix() << endl;
    for(int i = 0; i < 4; i++)
    {
    	if(!obj_exist[i])
    		continue;
    	cv::Mat temp_depth;
    	depth.copyTo(temp_depth,mask_vec[i]);

    	PointT p_world;
    	PointCloudT::Ptr pc_ptr(new PointCloudT);
    	for(int r = 0; r < depth.rows; r++)
    	{
    		const ushort* data = temp_depth.ptr<ushort>(r);
    		for(int c = 0; c < depth.cols; c++)
    		{
				Eigen::Vector3f point;
				if(data[c])
				{
					point[2] = data[c] * 0.000124987;   //depth scale, get it from realsense sdk
					point[0] = (c - cx) * point[2] / fx;
					point[1] = (r - cy) * point[2] / fy;

					Eigen::Vector3f point_world = trans_world * point;
					p_world.z = point_world[2];
					p_world.x = point_world[0];
					p_world.y = point_world[1];
					pc_ptr->push_back(p_world);
				}
    		}
    	}
    	Object o(pc_ptr,i);
    	object_vec.push_back(o);
    	//viewPC(o.pc_ptr,"pc");
    }
}

// get objecr with multiple instances
void eh_system::Frame::getObjectMul()
{
	std::vector<cv::Mat> mask_vec(4,cv::Mat());
	std::vector<bool> obj_exist(4,false); //index equals object ID

//------------------get mask for all kinds of objects-------------------------------
	for(int i = 0; i < fcn_vec.rows; i++)
	{  //fcn_vec is a n_pixel * n_class matrix
    	const float* data_r = fcn_vec.ptr<float>(i);
		int argMax = getArgMax(data_r,5);
			if(argMax == 0){
				if(obj_exist[0]){
					mask_vec[0].data[i] = 255;
				}
				else{
					mask_vec[0] = cv::Mat::zeros(depth.size(),CV_8UC1);
					obj_exist[0] = true;
				}
    		}
    		else if(argMax == 1){
				if(obj_exist[1]){
					mask_vec[1].data[i] = 255;
				}
				else{
					mask_vec[1] = cv::Mat::zeros(depth.size(),CV_8UC1);
					obj_exist[1] = true;
				}
    		}
    		// else if(argMax == 2){    //background
    		// }
    		else if(argMax == 3){  
				if(obj_exist[2]){
					mask_vec[2].data[i] = 255;
				}
				else{
					mask_vec[2] = cv::Mat::zeros(depth.size(),CV_8UC1);
					obj_exist[2] = true;
				}
    		}
    		else if(argMax == 4){
				if(obj_exist[3]){
					mask_vec[3].data[i] = 255;
				}
				else{
					mask_vec[3] = cv::Mat::zeros(depth.size(),CV_8UC1);
					obj_exist[3] = true;
				}
    		}
    }

    //for every class mask, detect multiple instances
        mask_instance.clear();
    for(int i = 0; i < mask_vec.size(); i++){
    	//cout << "nonZero:" << cv::countNonZero(mask_vec[i]) << endl;
    	if(cv::countNonZero(mask_vec[i]) < 50)
    		continue;
    	maskProcess(mask_vec[i],i);
    	//cout << i << " processed!" << endl;
    }
    cout << "mask instance size:  " << mask_instance.size() << endl;

    for(int i = 0; i < mask_instance.size(); i++)
    {
    	cv::Mat temp_depth;
    	depth.copyTo(temp_depth,mask_instance[i].mask);

    	PointT p_world;
    	PointCloudT::Ptr pc_ptr(new PointCloudT);
    	for(int r = 0; r < depth.rows; r++)
    	{
    		const ushort* data = temp_depth.ptr<ushort>(r);
    		for(int c = 0; c < depth.cols; c++)
    		{
				Eigen::Vector3f point;
				if(data[c])
				{
					point[2] = data[c] / Config::get<float>("DepthMapFactor");// * 0.000124987;   //depth scale, get it from realsense sdk
              
					if(point[2] > Config::get<float>("range_thres"))
						continue;

					point[0] = (c - cx) * point[2] / fx;
					point[1] = (r - cy) * point[2] / fy;

					Eigen::Vector3f point_world = trans_world * point;
					p_world.z = point_world[2];
					p_world.x = point_world[0];
					p_world.y = point_world[1];
					pc_ptr->push_back(p_world);
				}
    		}
    	}

    	if(pc_ptr->size() == 0)
    		continue;

		downSample(*pc_ptr,leaf_size);
		removeOut(*pc_ptr,mean_k,std_mul_thres);

    	Object o(pc_ptr,mask_instance[i].id);
    	object_vec.push_back(o);
    }
}

////get max row element
/// @param  mask		input mask
/// @param  out_put 	output mask
void eh_system::Frame::maskProcess(cv::Mat& mask,int id)
{
	cv::Mat temp;
	cv::morphologyEx(mask, temp, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));  
	cv::Mat element(Config::get<int>("erode_kernel_size"),Config::get<int>("erode_kernel_size"),CV_8U,cv::Scalar(1));  
	cv::erode(temp,temp,element);  

	cv::Mat src = temp.clone();

	//--------------------------------------find contours--------------------------------------------------
	int64 tick1 = cv::getTickCount();
	vector< vector<cv::Point> > contours;
	vector<cv::Vec4i> g_vHierarchy;
	cv::findContours(temp, contours, g_vHierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );
    
	cv::Rect ccomp;//定义重绘区域的最小边界矩形区域
	int area = 0;
    for(int i = 0; i < contours.size(); i++)
    {
    	if(contours[i].size() < contour_size)
	       continue;

	   	cv::Point p_temp= contours[i][contours[i].size() / 2];
	   	cv::Point p_right = p_temp + cv::Point(2,0);
		cv::Point p_left = p_temp + cv::Point(-2,0);
		cv::Point p_up = p_temp + cv::Point(0,-2);
		cv::Point p_down=  p_temp + cv::Point(0,2);
		cv::Point p_seed;
		cv::Mat g_maskImage = cv::Mat::zeros(temp.rows+2, temp.cols+2, CV_8UC1);

		// cv::imshow("temp",temp);
		// cv::waitKey();
	   	if( p_right.x < src.cols &&
	   		p_right.x >= 0 && 
	   		p_right.y >= 0 && 
	   		p_right.y < src.rows && src.at<uchar>(p_right)){
	   		p_seed = p_right;
	   	}
	   	else if(
	   		p_left.x < src.cols &&
	   		p_left.x >= 0 && 
	   		p_left.y >= 0 && 
	   		p_left.y < src.rows && src.at<uchar>(p_left)){
	   		p_seed = p_left;
	   	}	   	
	   	else if(p_up.x < src.cols &&
	   		p_up.x >= 0 && 
	   		p_up.y >= 0 && 
	   		p_up.y < src.rows && src.at<uchar>(p_up)){
	   		p_seed = p_up;
	   	}
	   	else if(p_down.x < src.cols &&
	   		p_down.x >= 0 && 
	   		p_down.y >= 0 && 
	   		p_down.y < src.rows && src.at<uchar>(p_down)){
	   		p_seed = p_down;
	   	}
	   	else{
	   		cout << "Can not find seed point!" << endl;
	   		continue;
	   	}
	   	cv::Mat src_ = src.clone();
		int a = cv::floodFill(src_, g_maskImage, p_seed, 
	   		cv::Scalar(255),&ccomp,cv::Scalar(40, 40, 40),
				cv::Scalar(40, 40, 40), 66304 + CV_FLOODFILL_FIXED_RANGE);
	   	if( a > area_size)
		{
			//cout << "flood fill!" << endl;
			// cv::imshow("floodFill",g_maskImage);
			// cv::waitKey();
			cv::Mat mask_new = cv::Mat::zeros(temp.rows, temp.cols, CV_8UC1);
			for(int i = 0; i < mask_new.rows; i++)
			{	
				uchar* data = mask_new.ptr<uchar>(i);	      //whole depth map 
				uchar*  dataMask = g_maskImage.ptr<uchar>(i+1);     //mask
				for(int j = 0; j < mask_new.cols; j++)
				{
					if(dataMask[j+1])
						data[j] = 255;
				}
			}
			eh_system::MaskStruct m(mask_new,id);
			mask_instance.push_back(m);
		}
    }
}

////get max row element
/// @param  data_row	row pointer of Mat
/// @param  num 		number of class
int eh_system::Frame::getArgMax(const float* data_row,int num)
{
	int res = 0;
	for(int i = 1; i < num; i++){
		if(data_row[res] < data_row[i])
			res = i;
	}
	return res;
}

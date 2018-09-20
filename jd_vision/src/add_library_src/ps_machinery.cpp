#include "opencv_bridge/ps_machinery.h"
#include "opencv_bridge/point_cloud.h"
#include "opencv_bridge/config.h"

namespace eh_system{
	
	PointCloudT readPLY(const char* file_name,bool with_color)
	{
		PointCloudT pc;
		 int numVertices = 0;

		std::ifstream ifs(file_name);
		if (!ifs.is_open())
	  	{
		    printf("Cannot open file...\n");
		    return pc;
	  	}
		std::string str;
		while (str.substr(0, 10) !="end_header")
		{
		  std::string entry = str.substr(0, 14);
		  if (entry == "element vertex")
		  {
		    numVertices = atoi(str.substr(15, str.size()-15).c_str());
		  }
		    std::getline(ifs, str);
		}
		for (int i = 0; i < numVertices; i++)
		{
			PointT p;
			if(with_color){
				ifs >> p.x >> p.y >> p.z >> p.r >> p.g >> p.b;
			}
			else{
				ifs >> p.x >> p.y >> p.z ;
			}
			pc.points.push_back(p);
		}
		return pc;
	};

	void writePLY(const char* file_name,PointCloudT::Ptr pc_ptr)
	{
		std::ofstream ofs(file_name);
		std::string header = "ply\nformat ascii 1.0\ncomment VCGLIB generated\n";
		ofs << header;

		std::stringstream ss; ss << pc_ptr->size();
		header = "element vertex " + ss.str() + '\n';
		ofs << header;

		header = "property float x\nproperty float y\nproperty float z\nelement face 0\nproperty list uchar int vertex_indices\nend_header\n";

		ofs << header;
		for(int i = 0; i < pc_ptr->size(); i++){
			ofs << pc_ptr->points[i].x << " "
				<< pc_ptr->points[i].y << " "
				<< pc_ptr->points[i].z << '\n';
		}
	}

	void viewPC(PointCloudT::Ptr pc_view,std::string window_name)
	{
	    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer(window_name));
	    viewer->setBackgroundColor(0, 0, 0);   
	     pcl::visualization::PointCloudColorHandlerCustom<PointT> cloud_in_color_h (pc_view, (int) 255 , (int) 255 ,
	        (int) 255);   //点为白色
	    viewer->addPointCloud(pc_view, cloud_in_color_h, "a");
	    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1.5, "a");
	    viewer->setCameraPosition(0,0,-1,0,0,1,0,-1,0);
	    viewer->addCoordinateSystem(1.0);

	    while (!viewer->wasStopped())
	        viewer->spinOnce();
	};

	bool icpPCL(PointCloudT::Ptr pc_source, PointCloudT::Ptr pc_target,int num_iter,cv::Mat& transMatrix,
		float* max_corr_dist,float corres_thres)
	{
		pcl::IterativeClosestPoint<PointT, PointT> icp;
		icp.setMaximumIterations (num_iter);
		icp.setMaxCorrespondenceDistance(corres_thres);//Config::get<float>("icp_thres"));  //阈值很重要！
		icp.setInputSource(pc_source);
		icp.setInputTarget (pc_target);
		icp.align (*pc_source);

		if(icp.hasConverged ())
		{
			Eigen::Matrix4f t;
			transMatrix = cv::Mat::eye(4,4,CV_32FC1);
			t = icp.getFinalTransformation().cast<float>();
			transMatrix.at<float>(0,0) = t(0,0); transMatrix.at<float>(0,1) = t(0,1);  transMatrix.at<float>(0,2) = t(0,2); transMatrix.at<float>(0,3) = t(0,3);
			transMatrix.at<float>(1,0) = t(1,0); transMatrix.at<float>(1,1) = t(1,1);  transMatrix.at<float>(1,2) = t(1,2); transMatrix.at<float>(1,3) = t(1,3);
			transMatrix.at<float>(2,0) = t(2,0); transMatrix.at<float>(2,1) = t(2,1);  transMatrix.at<float>(2,2) = t(2,2); transMatrix.at<float>(2,3) = t(2,3);
			*max_corr_dist = icp.getFitnessScore();
			return true;
		}
		else return false;
	}

	void sortEigenValue(cv::Mat& eValues,cv::Mat& eVectors,const cv::Mat& pc_trans_mat_centered)
	{
		int max_index = 0;
		int min_index = 0;
		for (int i = 1; i < 3; i++)
		{
			if(eValues.at<float>(i) > eValues.at<float>(max_index))
				max_index = i;
			if(eValues.at<float>(i) < eValues.at<float>(min_index))
				min_index = i;
		}
		int middle_index = 3 - max_index - min_index;

		cv::Mat sorted_eValues(1,3,CV_32FC1);
		cv::Mat rot_Mat(3,3,CV_32FC1);
		cv::Mat x_vec(3,1,CV_32FC1);
		cv::Mat y_vec(3,1,CV_32FC1);
		cv::Mat z_vec(3,1,CV_32FC1);

		sorted_eValues.at<float>(0) = eValues.at<float>(max_index);
		sorted_eValues.at<float>(1) = eValues.at<float>(middle_index);
		sorted_eValues.at<float>(2) = eValues.at<float>(min_index);

		for (int i = 0; i < 3 ;i++)   //X 
		{
			x_vec.at<float>(i,0) = eVectors.at<float>(max_index,i);   //x
			rot_Mat.at<float>(i,0) = eVectors.at<float>(max_index,i);
			y_vec.at<float>(i,0) = eVectors.at<float>(middle_index,i);  //y
			rot_Mat.at<float>(i,1) = eVectors.at<float>(middle_index,i);
			z_vec.at<float>(i,0) = eVectors.at<float>(min_index,i);  //z
			rot_Mat.at<float>(i,2) = eVectors.at<float>(min_index,i);
		}

		vector<float> dot_pro_y;
		vector<float> dot_pro_x;
		vector<float> dot_pro_z;

		double *x_min = new double(0);
		double *x_max = new double(0);

		double *y_min = new double(0);
		double *y_max = new double(0);

		double *z_min = new double(0);
		double *z_max = new double(0);

		for (int i = 0; i < pc_trans_mat_centered.rows; i++)
		{
			cv::Mat vec_tmp(3,1,CV_32FC1);
			const float* data = pc_trans_mat_centered.ptr<float>(i);
			vec_tmp.at<float>(0) = data[0];
			vec_tmp.at<float>(1) = data[1];
			vec_tmp.at<float>(2) = data[2];
			dot_pro_y.push_back(y_vec.dot(vec_tmp));
			dot_pro_x.push_back(x_vec.dot(vec_tmp));
			dot_pro_z.push_back(z_vec.dot(vec_tmp));
		}

		// cv::minMaxIdx(dot_pro_y,y_min,y_max);
		// cv::minMaxIdx(dot_pro_x,x_min,x_max);
		// cv::minMaxIdx(dot_pro_z,z_min,z_max);

		std::sort(dot_pro_y.begin(),dot_pro_y.end());
		std::sort(dot_pro_x.begin(),dot_pro_x.end());
		std::sort(dot_pro_z.begin(),dot_pro_z.end());

		//cout << "dot:\n";
		for(int i = 0; i < Config::get<int>("pca_points"); i++){
			//cout << dot_pro_z[i] << endl;
			*y_min += dot_pro_y[i];
			*y_max += dot_pro_y[pc_trans_mat_centered.rows-i];
			*x_min += dot_pro_x[i];
			*x_max += dot_pro_x[pc_trans_mat_centered.rows-i];
			*z_min += dot_pro_z[i];
			*z_max += dot_pro_z[pc_trans_mat_centered.rows-i];
		}

		// cout << "xmax " << *x_max << endl;
		// cout << "xmin " << *x_min << endl;
		// cout << "ymax " << *y_max << endl;
		// cout << "ymin " << *y_min << endl;
		// cout << "zmax " << *z_max << endl;
		// cout << "zmin " << *z_min << endl;

		if(abs(*x_max) - abs(*x_min) < (-1)*EPS)
		{
			x_vec *= -1;
		}
		if(abs(*y_max) - abs(*y_min) < (-1)*EPS)
		{
			y_vec *= -1;
		}
		if(abs(*z_max) - abs(*z_min) < (-1)*EPS)
		{
			z_vec *= -1;
		}
		bool rx(true),ry(true),rz(true);
		if( (abs(*x_max) - abs(*x_min) < EPS) &&
			(abs(*x_max) - abs(*x_min) > -1 * EPS)
		) 
		{
			rx = false;
			//cout << "x false" << endl;
		}
		if( (abs(*y_max) - abs(*y_min) < EPS) &&
			(abs(*y_max) - abs(*y_min) > -1 * EPS)
		) 
		{
			ry = false;
			//cout << "y false" << endl;
		}
		if( (abs(*z_max) - abs(*z_min) < EPS) &&
			(abs(*z_max) - abs(*z_min) > -1 * EPS)
		) 
		{
			rz = false;
			//cout << "z false" << endl;
		}
		if(rx && ry && rz){
			z_vec = x_vec.cross(y_vec);
		}
		else if(!rx && ry && rz){
			x_vec = y_vec.cross(z_vec);
		}
		else if(rx && !ry && rz){
			y_vec = z_vec.cross(x_vec);
		}
		else if(rx && ry && !rz){
			z_vec = x_vec.cross(y_vec);
		}
		else if(rx && !ry && !rz){
			z_vec = x_vec.cross(y_vec);
		}
		else if(!rx && ry && !rz){
			z_vec = x_vec.cross(y_vec);
		}
		else if(!rx && !ry && !rz){
			x_vec = y_vec.cross(z_vec);
		}
		else{
			z_vec = x_vec.cross(y_vec);
		}

		delete y_max;
		delete y_min;
		delete x_max;
		delete x_min;
		delete z_max;
		delete z_min;

		for (int i = 0; i < 3 ;i++) 
		{
			rot_Mat.at<float>(i,2) = z_vec.at<float>(i,0);
			rot_Mat.at<float>(i,0) = x_vec.at<float>(i,0);
			rot_Mat.at<float>(i,1) = y_vec.at<float>(i,0);
		}
		eValues = sorted_eValues;
		eVectors = rot_Mat;
	}


	PointCloudT::Ptr poseEstimationPCA(const PointCloud& scene,const PointCloud& model,cv::Mat& result)
	{
		cv::Mat pc_model = model.getMat();
		cv::Mat pc_scene = scene.getMat();
		cv::Point3f model_cg = model.getCG();
		cv::Point3f scene_cg = scene.getCG();

		//-------------mean normalization for both scene and model-----------------
		for(int i = 0; i < model.getNum(); i++)
		{
			float* data = pc_model.ptr<float>(i);
			data[0] -= model_cg.x;
			data[1] -= model_cg.y;
			data[2] -= model_cg.z;
		}
		for(int i = 0; i < scene.getNum(); i++)
		{
			float* data = pc_scene.ptr<float>(i);
			data[0] -= scene_cg.x;
			data[1] -= scene_cg.y;
			data[2] -= scene_cg.z;
		}

		//-------------pca for both scene and model-----------------
		cv::Mat M_scene = pc_scene.t() * pc_scene;
		cv::Mat e_values_scene;  
		cv::Mat e_vec_scene;  

		cv::Mat M_model = pc_model.t() * pc_model;
		cv::Mat e_values_model;  
		cv::Mat e_vec_model;  

		eigen(M_scene, e_values_scene, e_vec_scene);   
		eigen(M_model, e_values_model,e_vec_model); 

		sortEigenValue(e_values_model, e_vec_model,pc_model);   //特征值排序，计算旋转矩阵
		sortEigenValue(e_values_scene, e_vec_scene,pc_scene);   //特征值排序，计算旋转矩阵

		cv::Mat homo_pose_model = cv::Mat::eye(4,4,CV_32FC1);
		cv::Mat homo_pose_scene = cv::Mat::eye(4,4,CV_32FC1);
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				homo_pose_model.at<float>(i,j) = e_vec_model.at<float>(i,j);
				homo_pose_scene.at<float>(i,j) = e_vec_scene.at<float>(i,j);
			}
		}
		homo_pose_model.at<float>(0,3) = model_cg.x;
		homo_pose_model.at<float>(1,3) = model_cg.y;
		homo_pose_model.at<float>(2,3) = model_cg.z;

		homo_pose_scene.at<float>(0,3) = scene_cg.x;
		homo_pose_scene.at<float>(1,3) = scene_cg.y;
		homo_pose_scene.at<float>(2,3) = scene_cg.z;

		PointCloudT::Ptr pc_transformed_model = model.getPCPtr();
		PointCloudT::Ptr pc_transformed_scene = scene.getPCPtr();

		//将模型点云按PCA结果进行变换
		Eigen::Matrix4f transform_model = Eigen::Matrix4f::Identity();

		transform_model (0,0) = e_vec_model.at<float>(0,0);
		transform_model (0,1) = e_vec_model.at<float>(0,1);
		transform_model (0,2) = e_vec_model.at<float>(0,2);

		transform_model (1,0) = e_vec_model.at<float>(1,0);
		transform_model (1,1) = e_vec_model.at<float>(1,1);
		transform_model (1,2) = e_vec_model.at<float>(1,2);

		transform_model (2,0) = e_vec_model.at<float>(2,0);
		transform_model (2,1) = e_vec_model.at<float>(2,1);
		transform_model (2,2) = e_vec_model.at<float>(2,2);

		transform_model (0,3) = model_cg.x;
		transform_model (1,3) = model_cg.y;
		transform_model (2,3) = model_cg.z;

		transform_model = transform_model.inverse().eval();
		pcl::transformPointCloud (*pc_transformed_model, *pc_transformed_model, transform_model);

		// //将场景点云按PCA结果进行变换
		Eigen::Matrix4f transform_scene = Eigen::Matrix4f::Identity();

		transform_scene (0,0) = e_vec_scene.at<float>(0,0);
		transform_scene (0,1) = e_vec_scene.at<float>(0,1);
		transform_scene (0,2) = e_vec_scene.at<float>(0,2);

		transform_scene (1,0) = e_vec_scene.at<float>(1,0);
		transform_scene (1,1) = e_vec_scene.at<float>(1,1);
		transform_scene (1,2) = e_vec_scene.at<float>(1,2);

		transform_scene (2,0) = e_vec_scene.at<float>(2,0);
		transform_scene (2,1) = e_vec_scene.at<float>(2,1);
		transform_scene (2,2) = e_vec_scene.at<float>(2,2);

		transform_scene (0,3) = scene_cg.x;
		transform_scene (1,3) = scene_cg.y;
		transform_scene (2,3) = scene_cg.z;

		transform_scene = transform_scene.inverse().eval();
		pcl::transformPointCloud (*pc_transformed_scene, *pc_transformed_scene, transform_scene);

		//viewPC(pc_transformed_scene,"pc_transformed_scene");
		//viewPC(pc_transformed_model,"pc_transformed_model");

		cv::Mat icp_matrix = cv::Mat::eye(4,4,CV_32FC1);
		float* max_corr_dist = new float(0);
		if(!icpPCL(pc_transformed_model,pc_transformed_scene,Config::get<int>("icp_time"),icp_matrix,max_corr_dist))
		{
			cout << "ICP失败..." << endl;
		}
		result = homo_pose_scene * homo_pose_model.inv() * icp_matrix;
		return pc_transformed_scene;
	}

	void poseEstimationPPF(cv::ppf_match_3d::PPF3DDetector *detector,const PointCloudNorm& scene,const PointCloudNorm& model,cv::Mat& result)
	{
	   // cout << "PPF match started!" << endl;
	    vector<Pose3DPtr> results;
	    detector->match(scene.getMatNorm(), results, 1.0/5.0, 0.05);
	   // cout << "PPF match finished!" << endl;
	    int N = 1;
	    vector<Pose3DPtr> resultsSub(results.begin(),results.begin()+N);
		for (size_t i=0; i<resultsSub.size(); i++)
	    {
	        Pose3DPtr result = resultsSub[i];
	       // cout << "Pose Result " << i << endl;
	        //result->printPose();
	    }

		//将模型点云按PPF结果进行变换
		Eigen::Matrix4f transform_model = Eigen::Matrix4f::Identity();

		transform_model (0,0) = resultsSub[0]->pose[0];
		transform_model (0,1) = resultsSub[0]->pose[1];
		transform_model (0,2) = resultsSub[0]->pose[2];

		transform_model (1,0) = resultsSub[0]->pose[4];
		transform_model (1,1) = resultsSub[0]->pose[5];
		transform_model (1,2) = resultsSub[0]->pose[6];

		transform_model (2,0) = resultsSub[0]->pose[8];
		transform_model (2,1) = resultsSub[0]->pose[9];
		transform_model (2,2) = resultsSub[0]->pose[10];

		transform_model (0,3) = resultsSub[0]->pose[3];
		transform_model (1,3) = resultsSub[0]->pose[7];
		transform_model (2,3) = resultsSub[0]->pose[11];

		cv::Mat ppf_matrix(4,4,CV_64F,resultsSub[0]->pose);
		ppf_matrix.convertTo(ppf_matrix,CV_32FC1);
		//cout << "transform PPF\n" << ppf_matrix << endl;

		PointCloudT::Ptr pc_transformed_model = model.getPCPtr();
		PointCloudT::Ptr pc_scene = scene.getPCPtr();
		pcl::transformPointCloud (*pc_transformed_model, *pc_transformed_model, transform_model);

		//viewResult(pc_transformed_model,pc_scene,"model");

		cv::Mat icp_matrix = cv::Mat::eye(4,4,CV_32FC1);
		float* max_corr_dist = new float(0);
		if(!icpPCL(pc_transformed_model,pc_scene,Config::get<int>("icp_time"),icp_matrix,max_corr_dist,Config::get<float>("icp_thres_ppf")))
		{
			cout << "ICP失败..." << endl;
			result = ppf_matrix;
			return ;
		}
		//cout << "ICP Matrix\n" << icp_matrix << endl;
		result = icp_matrix * ppf_matrix;
		//cout << "PPF Final Matrix\n" << result << endl;
	}

	void Vec2Matrix(vector<float>& pose,  cv::Mat& poseMatrix)
	{
		CV_Assert(pose.size() == 6);
		cv::Mat rotVec = (cv::Mat_<float>(3,1)<< pose[3], pose[4], pose[5]);
		cv::Mat rotMat;
		Rodrigues(rotVec, rotMat);
		poseMatrix = cv::Mat::zeros(4, 4, CV_32FC1); 
		for (int i = 0; i < 3; i++ )
		{
			for (int j = 0; j < 3; j++)
			{
				poseMatrix.at<float>(i, j) = rotMat.at<float>(i, j);
			}
			poseMatrix.at<float>(i, 3) = pose[i];
		}
		poseMatrix.at<float>(3, 3) = 1.0;
	}

	void Matrix2Vec(cv::Mat& poseMatrix, vector<float>& poseVec)
	{
		CV_Assert(poseMatrix.rows == 4 && poseMatrix.cols == 4 && poseMatrix.type() == CV_32FC1);
		poseVec.clear();
		for (int i = 0; i < 3; i++)
		{
			poseVec.push_back(poseMatrix.at<float>(i, 3));
		}
		cv::Mat rotMat = cv::Mat::zeros(3, 3, CV_32FC1);
		for (int i = 0; i < 3; i++ )
		{
			for (int j = 0; j < 3; j++)
			{
				rotMat.at<float>(i, j) = poseMatrix.at<float>(i, j);
			}
		}
		cv::Mat rotVec;
		cv::Rodrigues(rotMat, rotVec);
		for (int i = 0; i < 3; i++)
		{
			poseVec.push_back(rotVec.at<float>(i));
		}
	}

}
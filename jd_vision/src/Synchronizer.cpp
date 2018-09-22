#include <cstdio>
#include "opencv2/opencv.hpp"
#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>
#include <camera_info_manager/camera_info_manager.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include "jd_vision/SourceFrame.h"
#include "jd_vision/RobotMsg.h"

using namespace cv;
using namespace std;
using namespace ros;
using namespace message_filters;

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, sensor_msgs::Image, jd_vision::RobotMsg> MySyncPolicy;

namespace jd_vision{
	class Synchronizer{
	private:
		ros::NodeHandle nh_;
		message_filters::Subscriber<sensor_msgs::Image>*  image_sub;
		message_filters::Subscriber<sensor_msgs::Image>*  depth_sub;
		message_filters::Subscriber<jd_vision::RobotMsg>* robot_sub;
		image_transport::ImageTransport it_;
		message_filters::Synchronizer<MySyncPolicy>* sync;
		ros::Publisher Synchronized_Msg;
	public:
		Synchronizer()
		: it_(nh_)
		{
			std::cout << "Structing function of Synchronizer "<<std::endl;
			Synchronized_Msg =	nh_.advertise<jd_vision::SourceFrame>("SourceFrame", 10);
            image_sub = new message_filters::Subscriber<sensor_msgs::Image>(nh_, "/camera/color/image_raw", 1);
            depth_sub = new message_filters::Subscriber<sensor_msgs::Image>(nh_, "/camera/depth/image_raw", 1);
			robot_sub 	  = new message_filters::Subscriber<jd_vision::RobotMsg>(nh_, "/ur", 1);
            sync      = new message_filters::Synchronizer<MySyncPolicy>(MySyncPolicy(10), *image_sub, *depth_sub, *robot_sub);
			sync->registerCallback(boost::bind(&Synchronizer::callBack_sync, this, _1, _2, _3));
		}
		~Synchronizer()
		{
			delete image_sub;
			delete depth_sub;
			delete robot_sub;
			delete sync;
		}
		void callBack_sync(	const sensor_msgs::ImageConstPtr& img_ptr,
			const sensor_msgs::ImageConstPtr& depth_ptr,
			const jd_vision::RobotMsg::ConstPtr& ur_ptr)
		{
			jd_vision::SourceFrame msg;
			msg.header=img_ptr->header;
			msg.color =*img_ptr;
			msg.depth =*depth_ptr;
            msg.robot_pose.resize(6);
            msg.robot_joint.resize(6);

			msg.robot_pose[0] = ur_ptr->data.tool_vector[0];
			msg.robot_pose[1] = ur_ptr->data.tool_vector[1];
			msg.robot_pose[2] = ur_ptr->data.tool_vector[2];
			msg.robot_pose[3] = ur_ptr->data.tool_vector[3];
			msg.robot_pose[4] = ur_ptr->data.tool_vector[4];
			msg.robot_pose[5] = ur_ptr->data.tool_vector[5];

			msg.robot_joint[0] = ur_ptr->data.q_actual[0];
			msg.robot_joint[1] = ur_ptr->data.q_actual[1];
			msg.robot_joint[2] = ur_ptr->data.q_actual[2];
			msg.robot_joint[3] = ur_ptr->data.q_actual[3];
			msg.robot_joint[4] = ur_ptr->data.q_actual[4];
			msg.robot_joint[5] = ur_ptr->data.q_actual[5];
			Synchronized_Msg.publish(msg);
		}
	};//end of class
}//end of namespace

int main(int argc, char** argv)
{
	ros::init(argc, argv, "Synchronizer");
	ros::NodeHandle n;
	jd_vision::Synchronizer Synchronizer;
	while(ros::ok())
	{
		ros::spin();
	}
	return 0;
}

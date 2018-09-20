#include "opencv_bridge/object.h"
#include "opencv_bridge/ps_machinery.h"


eh_system::Object::Object(const Object& other)
{
	//if(this != &other)
	//{
		pc_ptr = PointCloudT::Ptr(new PointCloudT(*(other.pc_ptr)));
		id = other.id;
		centre = cv::Point3f(other.centre.x,other.centre.y,other.centre.z);
	//}
};

eh_system::Object::Object(PointCloudT::Ptr pc,int id_)
{
	pc_ptr = PointCloudT::Ptr(new PointCloudT(*pc));
	id = id_;
	centre = cv::Point3f(0,0,0);
	for(int i = 0; i < pc->size();i++)
	{
		centre.x += pc->points[i].x;
		centre.y += pc->points[i].y;
		centre.z += pc->points[i].z;
	}
	centre.x /= pc->size();
	centre.y /= pc->size();
	centre.z /= pc->size();
}
void eh_system::Object::add(const Object& o)
{
	CV_Assert(o.id == id);
	
	float* f = new float;
	cv::Mat matrix;
	eh_system::icpPCL(o.pc_ptr,pc_ptr,5,matrix,f,0.01);
	delete f;

	*pc_ptr += *(o.pc_ptr);
	cv::Point3f p(0,0,0);
	for(int i = 0; i < pc_ptr->size(); i++)
	{
		p.x += pc_ptr->points[i].x;
		p.y += pc_ptr->points[i].y;
		p.z += pc_ptr->points[i].z;
	}
	p.x /= pc_ptr->size();  
	p.y /= pc_ptr->size();
	p.z /= pc_ptr->size();
	centre = p;
};

eh_system::Object& eh_system::Object::operator=(const eh_system::Object& other)
{
    if (this != &other)
    {
		pc_ptr = PointCloudT::Ptr(new PointCloudT(*(other.pc_ptr)));
		id = other.id;
		centre = other.centre;
    }
    return *this;
}
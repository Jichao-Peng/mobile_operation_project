#include "ros/ros.h"
#include "jrc_main/input.h"
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "iomanip"
#include "cassert"
using namespace std;
const int NUMBER = 20;

void readtxt(string file,jrc_main::input& input)
{
    ifstream infile; 
    infile.open(file.data());  
    assert(infile.is_open());   
    string s;
    int count = 0;
    while (getline(infile,s))
    {
        istringstream istr(s);
        std::cout<<s<<endl;        
        if(count == 0)
        {

           for(int i = 0; i < NUMBER; i ++)
           {
               istr>>input.request.names[i].data;
           }   
        }
        else
        {
            for(int i = 0; i < NUMBER; i ++)
            {
                istr>>input.request.numbers[i].data;
            }
        }
        count ++;
    }
    infile.close();
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "input");
    ros::NodeHandle nh;

    ros::ServiceClient input_client;
    input_client = nh.serviceClient<jrc_main::input>("input_service");
    jrc_main::input input;
    input.request.names.resize(NUMBER);
    input.request.numbers.resize(NUMBER);
    input.response.left_numbers.resize(NUMBER);
    
    string file = "/home/leon/jrc/src/jrc_main/src/wutileibie.txt";
    readtxt(file,input);

    ros::service::waitForService("input_service");

    if(input_client.call(input))
    {
        ROS_INFO_STREAM("The left number of all the objects are: ");
        for(int i = 0 ; i < NUMBER; i ++)
        {
            cout<<input.response.left_numbers[i].data<<" ";
        }
        cout<<endl;
    }

    // show input service
    // std::cout<<"file names:"<<endl;
    // for(int i = 0 ; i < NUMBER; i ++)
    // {
    //     cout<<input.request.names[i].data<<" ";
    // }
    // std::cout<<endl<<"file numbers:"<<endl;
    // for(int i = 0 ; i < NUMBER; i ++)
    // {
    //     cout<<input.request.numbers[i].data<<" ";
    // }
    // cout<<endl;
    
    return 0;
}


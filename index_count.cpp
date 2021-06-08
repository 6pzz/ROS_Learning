#include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息
#include <sstream>

int main(int argc, char  *argv[])
{   
    ros::init(argc,argv,"talker2");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("/test_index",10);	
    std_msgs::String msg;
    ros::Rate rate(10);
	int count = 0;
    
    while (ros::ok())
    {        
		std::stringstream ss;
		ss << "" << count;
        msg.data = ss.str();     
		pub.publish(msg);

        ROS_INFO("%s",ss.str().c_str());
        count++;

        rate.sleep();       
    }

    return 0;
}

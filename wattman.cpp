#include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"talker");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("/test_name",10);

    std_msgs::String msg;
    while (ros::ok())
    {
        msg.data = "wattman";
        pub.publish(msg);
        ROS_INFO("wattman");
    }
    return 0;
}
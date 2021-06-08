#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr &msg){
    ROS_INFO("%s",msg->data.c_str());
}

int main(int argc, char  *argv[])
{
    //初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"listener");
    //实例化 ROS 句柄   
    ros::NodeHandle nh;
    //实例化 订阅者 对象
    ros::Subscriber sub = nh.subscribe("/livox/lidar",10,doMsg);
 
    ros::spin();//循环读取接收的数据，并调用回调函数处理

    return 0;
}
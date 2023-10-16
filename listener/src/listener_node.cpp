//
// Created by dovejh on 23-10-16.
//
#include <iostream>
#include "ros/ros.h"
#include "talker/my_time.h"
using namespace std;

// 接收到订阅的消息后，会进入消息回调函数
void timeCallback(const talker::my_time::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    cout << "已收到一条消息：时间" << msg->count << " " << msg->time.sec << endl;
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "listener_node");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/now_time的topic，注册回调函数timeCallback
    ros::Subscriber time_sub = n.subscribe("/now_time", 1, timeCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
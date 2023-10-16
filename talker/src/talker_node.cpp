//
// Created by dovejh on 23-10-16.
//
#include <iostream>
#include <ros/ros.h>
#include "talker/my_time.h"

using namespace std;

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "talker_node");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher，发布名为/now_time的topic，消息类型为talker::my_time，队列长度1
    ros::Publisher time_pub = n.advertise<talker::my_time>("/now_time", 1);

    // 设置循环的频率
    ros::Rate loop_rate(1);

    unsigned int count = 1;
    while (ros::ok())
    {

        talker::my_time time_msg;
        time_msg.count = count;
        time_msg.time = ros::Time::now();

        // 发布消息
        time_pub.publish(time_msg);

        cout << "已发送一条消息：时间" << count << " " << time_msg.time.sec << endl;

        count++;
        if(count > 10000)
        {
            count = 0;
        }

        // 按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}
#include <ros/ros.h>
#include "robot_info_class.cpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "robot_info_node");

    RobotInfo robot;

    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        robot.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
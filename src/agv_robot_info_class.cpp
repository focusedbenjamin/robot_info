#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>

// Include base class
#include "robot_info_class.cpp"

class AGVRobotInfo : public RobotInfo
{
private:
    std::string maximum_payload;

public:
    AGVRobotInfo()
    {
        maximum_payload = "100 Kg";
    }

    void publish_data() override
    {
        robotinfo_msgs::RobotInfo10Fields msg;

        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;
        msg.data_field_05 = "maximum_payload: " + maximum_payload;

        pub.publish(msg);
    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "agv_robot_info_node");

    AGVRobotInfo agv_robot;

    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        agv_robot.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
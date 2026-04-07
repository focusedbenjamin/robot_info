#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>

class RobotInfo
{
protected:
    ros::NodeHandle nh;
    ros::Publisher pub;

    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;

public:
    RobotInfo()
    {
        pub = nh.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);

        robot_description = "Cooper100";
        serial_number = "567A359";
        ip_address = "169.254.5.180";
        firmware_version = "3.5.8";
    }

    virtual void publish_data()
    {
        robotinfo_msgs::RobotInfo10Fields msg;

        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;

        pub.publish(msg);
    }

    virtual ~RobotInfo() {}
};
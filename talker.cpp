//Dmytro Demchenko AA-42

#include "ros/ros.h"
#include "geometry_msgs/TwistStamped.h"

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");
  ros::NodeHandle nh;


  ros::Publisher vel_pub = nh.advertise<geometry_msgs::TwistStamped>("/uav/velocity", 10);


  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    geometry_msgs::TwistStamped msg;


    msg.header.stamp = ros::Time::now();
    msg.header.frame_id = "base_link";


    msg.twist.linear.x = 25.0;
    msg.twist.linear.y = 0.0;
    msg.twist.linear.z = 0.0;


    vel_pub.publish(msg);

    ROS_INFO("[UAV AUTOPILOT] Cruising speed: %.1f m/s", msg.twist.linear.x);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

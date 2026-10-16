//Dmytro Demchenko AA-42

#include "ros/ros.h"
#include "geometry_msgs/TwistStamped.h"


void velocityCallback(const geometry_msgs::TwistStamped::ConstPtr& msg)
{
  ROS_INFO("[GCS MONITOR] Received UAV speed: %.2f m/s (frame: %s)",
           msg->twist.linear.x,
           msg->header.frame_id.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;

 
  ros::Subscriber vel_sub = nh.subscribe("/uav/velocity", 10, velocityCallback);

  ROS_INFO("UAV Ground Station Monitor started. Waiting for speed data...");


  ros::spin();

  return 0;
}

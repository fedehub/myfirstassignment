#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include <iostream>
#include <nav_msgs/Odometry.h>
#include "myfirstassignment/rdm.h"
#include <math.h>

ros::Publisher pub;

ros::ServiceClient client;

myfirstassignment::rdm rand_position;

int distance_btw_points(int a, int b){
	return sqrt(a^2 +b^2);
}


void subscriberCallback(const nav_msgs::Odometry::ConstPtr& pose_msg)
{
   geometry_msgs::Twist msg_sent;

   ROS_INFO(" coordinates of robot position [ %f %f]",pose_msg->pose.pose.position.x,pose_msg->pose.pose.position.y);

   ROS_INFO("coordinates of robot target [ %f %f]",rand_position.response.random_x,rand_position.response.random_y);
 	
   int delta_x = rand_position.response.random_x - pose_msg->  pose.pose.position.x;
   int delta_y = rand_position.response.random_y - pose_msg->  pose.pose.position.y;
   
   int mydistance = distance_btw_points(delta_x,delta_y);
	
   // checking 0.1 condition

   if(mydistance < 0.1){
	
	ROS_INFO("target reached");
	client.call(rand_position);	
   }
   
   else if (mydistance > 0.1){
   
   	msg_sent.linear.x = 1*delta_x;
    	msg_sent.linear.y= 1*delta_y;
	
	pub.publish(msg_sent);
	
	ROS_INFO("I am reaching the target");

   }

  
}

// defining distance btw two points



int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "random_movement");
  
  ros::NodeHandle n;
  
  client = n.serviceClient<myfirstassignment::rdm>("/random");
  client.call(rand_position);


  ros::Subscriber sub = n.subscribe("/odom", 1000, subscriberCallback);
  
  pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

  ros::spin();

  return 0;
}

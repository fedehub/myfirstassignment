#include "ros/ros.h"
#include "assignment1/random.h"
#include <math.h>


bool Rand (assignment1::random::Request &req, assignment1::random::Response &res){
	res.random_x = -6 + rand()%12;
	res.random_y = -6 + rand()%12;
    
	return true;
}



int main(int argc, char **argv)
{
   ros::init(argc, argv, "random");

   ros::NodeHandle n;

   ros::ServiceServer service= n.advertiseService("/random", Rand);

   ros::spin();

   return 0;
}


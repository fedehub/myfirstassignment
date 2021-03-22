#include "ros/ros.h"
#include "myfirstassignment/rdm.h"
#include <math.h>


bool Rand (myfirstassignment::rdm::Request &req, myfirstassignment::rdm::Response &res){
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


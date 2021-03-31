/* author: Federico Civetta 
 * 
 * 
 * FIRST ASSIGNMENT 
 * Research track (first module) 
 *
 * Second Node:
 * A Server, whose purpose is to compute 2 random numbers
*/

#include "ros/ros.h"
#include "myfirstassignment/rdm.h"
#include <math.h>


/**
 *@brief This function is called under request. It ask for a request and returns the target's coordinates
 *@param req  the request received from the client (none)
 *@param res  the response returned to the clien (the random coordinates within a specific interval)
 *@retval the random number (True or False)
 */

bool Rand (myfirstassignment::rdm::Request &req, myfirstassignment::rdm::Response &res){

        res.random_x = rand()%(12+1) -6;
        res.random_y = rand()%(12+1) -6;
	return true;
}


// Main definition
int main(int argc, char **argv)
{
   // Initialization of the node "random"
   ros::init(argc, argv, "random");

   // Setting-up the node handle
   ros::NodeHandle n;

   // Defining the service and specifying the callback function Rand
   ros::ServiceServer service= n.advertiseService("/random", Rand);

   // It avoids the exiting grom the main thread until ROS invokes (ctrl-C)
   ros::spin();

   return 0;
}


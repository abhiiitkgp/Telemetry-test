/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/App/qnode.hpp"
//#include "ros/ros.h"
//#include "std_msgs/String.h"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace App {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"App");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
    /*chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);*/
    chatter_subscriber = n.subscribe("chatter", 1, &QNode::chatterCallback,this);
    chatter_subscriber1 = n.subscribe("chatter", 1, &QNode::chatterCallback1,this);
    chatter_subscriber2 = n.subscribe("chatter", 1, &QNode::chatterCallback2,this);
    chatter_subscriber3 = n.subscribe("chatter", 1, &QNode::chatterCallback3,this);
    chatter_subscriber4= n.subscribe("chatter", 1, &QNode::chatterCallback4,this);
    chatter_subscriber5= n.subscribe("chatter", 1, &QNode::chatterCallback5,this);
    chatter_subscriber6= n.subscribe("chatter", 1, &QNode::chatterCallback6,this);

	start();

	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"App");
	if ( ! ros::master::check() ) {
        return false;
	}
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
    //chatter_subscriber = n.subscribe("chatter", 1000, &QNode::chatterCallback,this);
    chatter_subscriber1 = n.subscribe("chatter", 1, &QNode::chatterCallback1,this);
    chatter_subscriber2 = n.subscribe("chatter", 1, &QNode::chatterCallback2,this);
    chatter_subscriber3 = n.subscribe("chatter", 1, &QNode::chatterCallback3,this);
    chatter_subscriber4= n.subscribe("chatter", 1, &QNode::chatterCallback4,this);
    chatter_subscriber5= n.subscribe("chatter", 1, &QNode::chatterCallback5,this);
    chatter_subscriber6= n.subscribe("chatter", 1, &QNode::chatterCallback6,this);

    start();
    return true;
}


void QNode::run() {
    ros::Rate loop_rate(10);
	int count = 0;
	while ( ros::ok() ) {

		std_msgs::String msg;
		std::stringstream ss;
        ss  << count;
		msg.data = ss.str();
        //chatter_subscriber.publish(msg);
        //log(Info,std::string("I sent: ")+msg.data);
		ros::spinOnce();
		loop_rate.sleep();
        ++count;


	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  _msg = std::string(msg->data.c_str());
  Q_EMIT loggingUpdated();

}

void QNode::chatterCallback1(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  _msg1 = std::string(msg->data.c_str());
  Q_EMIT loggingUpdated1();

}
void QNode::chatterCallback2(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  _msg2 = std::string(msg->data.c_str());
  Q_EMIT loggingUpdated2();

}
void QNode::chatterCallback3(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  _msg3= std::string(msg->data.c_str());
  Q_EMIT loggingUpdated3();

}
void QNode::chatterCallback4(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  _msg4 = std::string(msg->data.c_str());
  Q_EMIT loggingUpdated4();

}
void QNode::chatterCallback5(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  _msg5 = std::string(msg->data.c_str());
  Q_EMIT loggingUpdated5();

}
void QNode::chatterCallback6(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  _msg6 = std::string(msg->data.c_str());
  Q_EMIT loggingUpdated6();

}
}  // namespace App

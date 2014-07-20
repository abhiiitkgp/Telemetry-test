/**
 * @file /include/App/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef App_QNODE_HPP_
#define App_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <std_msgs/String.h>
#include <QStringListModel>


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace App {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
    bool init(const std::string &master_url, const std::string &host_url);
    void run();
    void chatterCallback(const std_msgs::String::ConstPtr& msg);
    void chatterCallback1(const std_msgs::String::ConstPtr& msg);
     void chatterCallback2(const std_msgs::String::ConstPtr& msg);
      void chatterCallback3(const std_msgs::String::ConstPtr& msg);
       void chatterCallback4(const std_msgs::String::ConstPtr& msg);
        void chatterCallback5(const std_msgs::String::ConstPtr& msg);
         void chatterCallback6(const std_msgs::String::ConstPtr& msg);
    std::string _msg;
    std::string _msg1;
    std::string _msg2;
    std::string _msg3;
    std::string _msg4;
    std::string _msg5;
    std::string _msg6;

Q_SIGNALS:
	void loggingUpdated();
    void loggingUpdated1();
    void loggingUpdated2();
    void loggingUpdated3();
    void loggingUpdated4();
    void loggingUpdated5();
    void loggingUpdated6();
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
    ros::Subscriber chatter_subscriber;
    ros::Subscriber chatter_subscriber1;
    ros::Subscriber chatter_subscriber2;
    ros::Subscriber chatter_subscriber3;
    ros::Subscriber chatter_subscriber4;
    ros::Subscriber chatter_subscriber5;
    ros::Subscriber chatter_subscriber6;
};

}  // namespace App

#endif /* App_QNODE_HPP_ */

#include "ros/ros.h"
#include "std_msgs/String.h"


#include <sstream>





int int main(int argc, char const *argv[]) {

  ros::init(argc, argv, "testTalker");

  ros::NodeHandle n;


  ros::Publisher testpub = n.advertise<std_msgs::String>("topic_test",1000);





  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok()) {
    std_msgs::String msg;

    std::stringstream ss;
    ss <<"test_msg_send" << count;
    msg.data = ss.str();

    topic_test.publish(msg);

    ROS_INFO("%s", msg.data.c_str());

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}

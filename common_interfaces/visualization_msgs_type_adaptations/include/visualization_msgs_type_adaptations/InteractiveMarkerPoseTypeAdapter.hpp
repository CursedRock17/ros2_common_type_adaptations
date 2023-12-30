#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERPOSETYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERPOSETYPEADAPTER_HPP_

#include <string>

#include "visualization_msgs/msg/interactive_marker_pose.hpp"
#include "rclcpp/type_adapter.hpp"

#include "std_msgs/msg/header.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs_type_adaptations/include/PoseTypeAdapter.hpp"

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;
using PoseTypeAdapter = rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>;

struct InteractiveMarkerPose
{
  Header header;
  Pose pose;
  std::string name;
};


template<>
struct rclcpp::TypeAdapter<
   InteractiveMarkerPose,
   visualization_msgs::msg::InteractiveMarkerPose
>
{
  using is_specialized = std::true_type;
  using custom_type = InteractiveMarkerPose;
  using ros_message_type = visualization_msgs::msg::InteractiveMarkerPose;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    PoseTypeAdapter::convert_to_ros_message(source.pose, destination.pose);
    destination.name = source.name;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    PoseTypeAdapter::convert_to_custom(source.pose, destination.pose);
    destination.name = source.name;
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERPOSETYPEADAPTER_HPP_

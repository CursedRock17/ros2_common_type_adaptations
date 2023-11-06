#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSESTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSESTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "PoseTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct PoseStamped
{
  Pose pose;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   PoseStamped,
   geometry_msgs::msg::PoseStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = PoseStamped;
  using ros_message_type = geometry_msgs::msg::PoseStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>::convert_to_ros_message(
      source.pose, destination.pose);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>::convert_to_custom(
      source.pose, destination.pose);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSESTAMPEDTYPEADAPTER_HPP_

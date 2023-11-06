#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSESTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSESTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose.hpp"

#include "QuaternionTypeAdapter.hpp"
#include "PointTypeAdapter.hpp"

struct Pose
{
  Point position;
  Quaternion quaternion;
};

template<>
struct rclcpp::TypeAdapter<
   Pose,
   geometry_msgs::msg::Pose
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Pose;
  using ros_message_type = geometry_msgs::msg::Pose;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Point, std_msgs::msg::Point>::convert_to_ros_message(
      source.position, destination.position);
    rclcpp::TypeAdapter<Quaternion, geometry_msgs::msg::Quaternion>::convert_to_ros_message(
      source.quaternion, destination.quaternion);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Point, std_msgs::msg::Point>::convert_to_custom(
      source.position, destination.position);
    rclcpp::TypeAdapter<Quaternion, geometry_msgs::msg::Quaternion>::convert_to_custom(
      source.quaternion, destination.quaternion);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSESTAMPEDTYPEADAPTER_HPP_

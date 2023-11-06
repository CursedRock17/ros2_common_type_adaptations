#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/vector3.hpp"

#include "Vector3TypeAdapter.hpp"

struct Twist
{
  Vector3 linear;
  Vector3 angular;
};

template<>
struct rclcpp::TypeAdapter<
   Twist,
   geometry_msgs::msg::Twist
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Twist;
  using ros_message_type = geometry_msgs::msg::Twist;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_ros_message(
      source.linear, destination.linear);
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_ros_message(
      source.angular, destination.angular);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_custom(
      source.linear, destination.linear);
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_custom(
      source.angular, destination.angular);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTTYPEADAPTER_HPP_

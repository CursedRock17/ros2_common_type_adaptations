#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__WRENCHTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__WRENCHTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/wrench.hpp"
#include "geometry_msgs/msg/vector3.hpp"

#include "Vector3TypeAdapter.hpp"

struct Wrench
{
  Vector3 force;
  Vector3 torque;
};

template<>
struct rclcpp::TypeAdapter<
   Wrench,
   geometry_msgs::msg::Wrench
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Wrench;
  using ros_message_type = geometry_msgs::msg::Wrench;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_ros_message(
      source.force, destination.force);
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_ros_message(
      source.torque, destination.torque);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_custom(
      source.force, destination.force);
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_custom(
      source.torque, destination.torque);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__WRENCHTYPEADAPTER_HPP_

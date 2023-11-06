#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTSTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTSTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "TwistTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct TwistStamped
{
  Twist twist;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   TwistStamped,
   geometry_msgs::msg::TwistStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = TwistStamped;
  using ros_message_type = geometry_msgs::msg::TwistStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Twist, geometry_msgs::msg::Twist>::convert_to_ros_message(
      source.twist, destination.twist);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Twist, geometry_msgs::msg::Twist>::convert_to_custom(
      source.twist, destination.twist);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTSTAMPEDTYPEADAPTER_HPP_

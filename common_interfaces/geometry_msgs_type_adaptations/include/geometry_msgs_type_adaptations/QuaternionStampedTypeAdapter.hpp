#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__QUATERNIONSTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__QUATERNIONSTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "geometry_msgs/msg/quaternion_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "QuaternionTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct QuaternionStamped
{
  Quaternion quaternion;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   QuaternionStamped,
   geometry_msgs::msg::QuaternionStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = QuaternionStamped;
  using ros_message_type = geometry_msgs::msg::QuaternionStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Quaternion, geometry_msgs::msg::Quaternion>::convert_to_ros_message(
      source.quaternion, destination.quaternion);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Quaternion, geometry_msgs::msg::Quaternion>::convert_to_custom(
      source.quaternion, destination.quaternion);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__QUATERNIONSTAMPEDTYPEADAPTER_HPP_

#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELSTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELSTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/accel.hpp"
#include "geometry_msgs/msg/accel_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "AccelTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct AccelStamped
{
  Accel accel;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   AccelStamped,
   geometry_msgs::msg::AccelStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = AccelStamped;
  using ros_message_type = geometry_msgs::msg::AccelStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Accel, geometry_msgs::msg::Accel>::convert_to_ros_message(
      source.accel, destination.accel);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Accel, geometry_msgs::msg::Accel>::convert_to_custom(
      source.accel, destination.accel);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELSTAMPEDTYPEADAPTER_HPP_

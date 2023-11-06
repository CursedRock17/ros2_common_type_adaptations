#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__WRENCHSTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__WRENCHSTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/wrench.hpp"
#include "geometry_msgs/msg/wrench_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "WrenchTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct WrenchStamped
{
  Wrench wrench;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   WrenchStamped,
   geometry_msgs::msg::WrenchStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = WrenchStamped;
  using ros_message_type = geometry_msgs::msg::WrenchStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Wrench, geometry_msgs::msg::Wrench>::convert_to_ros_message(
      source.wrench, destination.wrench);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Wrench, geometry_msgs::msg::Wrench>::convert_to_custom(
      source.wrench, destination.wrench);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__WRENCHSTAMPEDTYPEADAPTER_HPP_

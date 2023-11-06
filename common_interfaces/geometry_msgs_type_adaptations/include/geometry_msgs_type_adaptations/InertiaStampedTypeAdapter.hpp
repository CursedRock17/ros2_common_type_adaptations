#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__INERTIASTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__INERTIASTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/inertia.hpp"
#include "geometry_msgs/msg/inertia_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "InertiaTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct InertiaStamped
{
  Inertia inertia;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   InertiaStamped,
   geometry_msgs::msg::InertiaStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = InertiaStamped;
  using ros_message_type = geometry_msgs::msg::InertiaStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Inertia, geometry_msgs::msg::Inertia>::convert_to_ros_message(
      source.inertia, destination.inertia);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Inertia, geometry_msgs::msg::Inertia>::convert_to_custom(
      source.inertia, destination.inertia);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__INERTIASTAMPEDTYPEADAPTER_HPP_

#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__VECTOR3STAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__VECTOR3STAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/vector3_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "Vector3TypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct Vector3Stamped
{
  Vector3 vector;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   Vector3Stamped,
   geometry_msgs::msg::Vector3Stamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Vector3Stamped;
  using ros_message_type = geometry_msgs::msg::Vector3Stamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_ros_message(
      source.vector, destination.vector);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_custom(
      source.vector, destination.vector);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__VECTOR3STAMPEDTYPEADAPTER_HPP_

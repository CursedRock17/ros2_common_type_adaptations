#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__TRANSFORMSTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__TRANSFORMSTAMPEDTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/transform.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "TransformTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct TransformStamped
{
  Transform transform;
  std::string child_frame_id;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   TransformStamped,
   geometry_msgs::msg::TransformStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = TransformStamped;
  using ros_message_type = geometry_msgs::msg::TransformStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Transform, geometry_msgs::msg::Transform>::convert_to_ros_message(
      source.transform, destination.transform);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
    destination.child_frame_id = source.child_frame_id;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Transform, geometry_msgs::msg::Transform>::convert_to_custom(
      source.transform, destination.transform);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
    destination.child_frame_id = source.child_frame_id;
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__TRANSFORMSTAMPEDTYPEADAPTER_HPP_

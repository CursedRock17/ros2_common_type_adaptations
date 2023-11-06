#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__TRANSFORMSTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__TRANSFORMSTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/transform.hpp"

#include "QuaternionTypeAdapter.hpp"
#include "Vector3TypeAdapter.hpp"

struct Transform
{
  Vector3 translation;
  Quaternion rotation;
};

template<>
struct rclcpp::TypeAdapter<
   Transform,
   geometry_msgs::msg::Transform
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Transform;
  using ros_message_type = geometry_msgs::msg::Transform;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, std_msgs::msg::Vector3>::convert_to_ros_message(
      source.translation, destination.translation);
    rclcpp::TypeAdapter<Quaternion, geometry_msgs::msg::Quaternion>::convert_to_ros_message(
      source.rotation, destination.rotations);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, std_msgs::msg::Vector3>::convert_to_custom(
      source.translation, destination.translation);
    rclcpp::TypeAdapter<Quaternion, geometry_msgs::msg::Quaternion>::convert_to_custom(
      source.rotation, destination.rotations);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__TRANSFORMSTAMPEDTYPEADAPTER_HPP_

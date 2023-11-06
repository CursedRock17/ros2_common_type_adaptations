#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__VECTOR3TYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__VECTOR3TYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/vector3.hpp"

struct Vector3
{
  double x;
  double y;
  double z;
};

template<>
struct rclcpp::TypeAdapter<
   Vector3,
   geometry_msgs::msg::Vector3
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Vector3;
  using ros_message_type = geometry_msgs::msg::Vector3;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.x = source.x;
    destination.y = source.y;
    destination.z = source.z;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.x = source.x;
    destination.y = source.y;
    destination.z = source.z;
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__VECTOR3TYPEADAPTER_HPP_

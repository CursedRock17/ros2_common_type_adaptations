#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POINT32TYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POINT32TYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/point32.hpp"

struct Point32
{
  float x;
  float y;
  float z;
};

template<>
struct rclcpp::TypeAdapter<
   Point32,
   geometry_msgs::msg::Point32
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Point32;
  using ros_message_type = geometry_msgs::msg::Point32;

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

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POINT32TYPEADAPTER_HPP_

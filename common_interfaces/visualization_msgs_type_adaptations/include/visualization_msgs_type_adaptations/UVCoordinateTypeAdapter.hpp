#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__UVCOORDINATETYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__UVCOORDINATETYPEADAPTER_HPP_

#include "visualization_msgs/msg/uv_coordinate.hpp"
#include "rclcpp/type_adapter.hpp"

struct UVCoordinate
{
  float u;
  float v;
};


template<>
struct rclcpp::TypeAdapter<
   UVCoordinate,
   visualization_msgs::msg::UVCoordinate
>
{
  using is_specialized = std::true_type;
  using custom_type = UVCoordinate;
  using ros_message_type = visualization_msgs::msg::UVCoordinate;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.u = source.u;
    destination.v = source.v;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.u = source.u;
    destination.v = source.v;
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__UVCOORDINATETYPEADAPTER_HPP_

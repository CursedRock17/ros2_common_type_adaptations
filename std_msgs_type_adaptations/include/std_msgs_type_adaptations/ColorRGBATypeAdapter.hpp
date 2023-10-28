#ifndef STD_MSGS_TYPE_ADAPTATIONS__COLORRGBATYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__COLORRGBATYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/color_rgba.hpp"

struct ColorRGBA
{
  float r;
  float g;
  float b;
  float a;
};

template<>
struct rclcpp::TypeAdapter<
   ColorRGBA,
   std_msgs::msg::ColorRGBA
>
{
  using is_specialized = std::true_type;
  using custom_type = ColorRGBA;
  using ros_message_type = std_msgs::msg::ColorRGBA;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.r = source.r;
    destination.g = source.g;
    destination.b = source.b;
    destination.a = source.a;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.r = source.r;
    destination.g = source.g;
    destination.b = source.b;
    destination.a = source.a;
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__COLORRGBATYPEADAPTER_HPP_

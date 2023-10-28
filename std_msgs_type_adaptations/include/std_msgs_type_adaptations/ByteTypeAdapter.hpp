#ifndef STD_MSGS_TYPE_ADAPTATIONS__BYTETYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__BYTETYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/byte.hpp"

template<>
struct rclcpp::TypeAdapter<
   unsigned char,
   std_msgs::msg::Byte
>
{
  using is_specialized = std::true_type;
  using custom_type = unsigned char;
  using ros_message_type = std_msgs::msg::Byte;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.data = source;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination = source.data;
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__BYTETYPEADAPTER_HPP_

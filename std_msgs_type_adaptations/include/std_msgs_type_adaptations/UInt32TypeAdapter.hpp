#ifndef STD_MSGS_TYPE_ADAPTATIONS__UINT32TYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__UINT32TYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/u_int32.hpp"

template<>
struct rclcpp::TypeAdapter<
   unsigned long,
   std_msgs::msg::UInt32
>
{
  using is_specialized = std::true_type;
  using custom_type = unsigned long;
  using ros_message_type = std_msgs::msg::UInt32;

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

#endif  // STD_MSGS_TYPE_ADAPTATIONS__UINT32TYPEADAPTER_HPP_

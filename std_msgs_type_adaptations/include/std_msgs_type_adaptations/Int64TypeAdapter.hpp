#ifndef STD_MSGS_TYPE_ADAPTATIONS__INT64TYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__INT64TYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/int64.hpp"

template<>
struct rclcpp::TypeAdapter<
  long long,
  std_msgs::msg::Int64
>
{
  using is_specialized = std::true_type;
  using custom_type = long long;
  using ros_message_type = std_msgs::msg::Int64;

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

#endif  // STD_MSGS_TYPE_ADAPTATIONS__INT64TYPEADAPTER_HPP_

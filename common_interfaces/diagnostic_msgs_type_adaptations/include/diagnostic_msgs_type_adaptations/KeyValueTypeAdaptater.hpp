#ifndef STD_MSGS_TYPE_ADAPTATIONS__KEYVALUETYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__KEYVALUETYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/key_value.hpp"

struct KeyValue
{
  std::string key;
  std::string value;
}

template<>
struct rclcpp::TypeAdapter<
   KeyValue,
   std_msgs::msg::KeyValue
>
{
  using is_specialized = std::true_type;
  using custom_type = KeyValue;
  using ros_message_type = std_msgs::msg::KeyValue;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.key = source.key;
    destination.value = source.value;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.key = source.key;
    destination.value = source.value;
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__KEYVALUETYPEADAPTER_HPP_

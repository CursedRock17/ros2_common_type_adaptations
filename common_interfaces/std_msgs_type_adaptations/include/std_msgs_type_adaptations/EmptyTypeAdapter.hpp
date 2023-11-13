#ifndef STD_MSGS_TYPE_ADAPTATIONS__EMPTYTYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__EMPTYTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/empty.hpp"

struct Empty {};

template<>
struct rclcpp::TypeAdapter<
   Empty,
   std_msgs::msg::Empty
>
{
  using is_specialized = std::true_type;
  using custom_type = Empty;
  using ros_message_type = std_msgs::msg::Empty;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    (void)source;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    (void)source;
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__EMPTYTYPEADAPTER_HPP_

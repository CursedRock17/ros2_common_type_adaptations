#ifndef STD_MSGS_TYPE_ADAPTATIONS__DURATIONTYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__DURATIONTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "builtin_interfaces/msg/duration.hpp"

struct Duration
{
  long sec;
  unsigned long nanosec;
};

template<>
struct rclcpp::TypeAdapter<
   Duration,
   builtin_interfaces::msg::Duration
>
{
  using is_specialized = std::true_type;
  using custom_type = Duration;
  using ros_message_type = builtin_interfaces::msg::Duration;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.sec = source.sec;
    destination.nanosec = source.nanosec;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.sec = source.sec;
    destination.nanosec = source.nanosec;
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__DURATIONTYPEADAPTER_HPP_

#ifndef STD_MSGS_TYPE_ADAPTATIONS__TIMETYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__TIMETYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "builtin_interfaces/msg/time.hpp"

struct Time
{
  long sec;
  unsigned long nanosec;
};

template<>
struct rclcpp::TypeAdapter<
   Time,
   builtin_interfaces::msg::Time
>
{
  using is_specialized = std::true_type; using custom_type = Time;
  using ros_message_type = builtin_interfaces::msg::Time;

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

#endif  // STD_MSGS_TYPE_ADAPTATIONS__TIMETYPEADAPTER_HPP_

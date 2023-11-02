#ifndef ROSGRAPH_MSGS_TYPE_ADAPTATIONS__CLOCKTYPEADAPTER_HPP_
#define ROSGRAPH_MSGS_TYPE_ADAPTATIONS__CLOCKTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "rosgraph_msgs/msg/clock.hpp"

#include "builtin_interfaces/msg/time.hpp"
#include "builtin_interfaces_type_adaptations/include/TimeTypeAdapter.hpp"

template<>
struct rclcpp::TypeAdapter<
  builtin_interfaces::msg::Time,
  rosgraph_msgs::msg::Clock
>
{
  using is_specialized = std::true_type;
  using custom_type = builtin_interfaces::msg::Time;
  using ros_message_type = rosgraph_msgs::msg::Clock;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>::convert_to_ros_message(source, destination.clock);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>::convert_to_custom(source.clock, destination);
  }
};

#endif  // ROSGRAPH_MSGS_TYPE_ADAPTATIONS__CLOCKTYPEADAPTER_HPP_

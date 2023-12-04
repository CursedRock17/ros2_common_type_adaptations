#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__FLOATINGPOINTRANGETYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__FLOATINGPOINTRANGETYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/floating_point_range.hpp"

struct FloatingPointRange
{
  double from_value;
  double to_value;
  double step;
};

template<>
struct rclcpp::TypeAdapter<
   FloatingPointRange,
   rcl_interfaces::msg::FloatingPointRange
>
{
  using is_specialized = std::true_type;
  using custom_type = FloatingPointRange;
  using ros_message_type = rcl_interfaces::msg::FloatingPointRange;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.from_value = source.from_value;
    destination.to_value = source.to_value;
    destination.step = source.step;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.from_value = source.from_value;
    destination.to_value = source.to_value;
    destination.step = source.step;
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__FLOATINGPOINTRANGETYPEADAPTER_HPP_

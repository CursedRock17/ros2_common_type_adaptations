#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__INTEGERRANGETYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__INTEGERRANGETYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/integer_range.hpp"

struct IntegerRange
{
  long long from_value;
  long long to_value;
  unsigned long long step;
};

template<>
struct rclcpp::TypeAdapter<
   IntegerRange,
   rcl_interfaces::msg::IntegerRange
>
{
  using is_specialized = std::true_type;
  using custom_type = IntegerRange;
  using ros_message_type = rcl_interfaces::msg::IntegerRange;

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

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__INTEGERRANGETYPEADAPTER_HPP_

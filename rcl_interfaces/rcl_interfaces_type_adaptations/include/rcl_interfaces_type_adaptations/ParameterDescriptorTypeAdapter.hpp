#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERDESCRIPTORTYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERDESCRIPTORTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/parameter_descriptor.hpp"
#include "rcl_interfaces/msg/floating_point_range.hpp"
#include "rcl_interfaces/msg/integer_range.hpp"

#include "FloatingPointRangeTypeAdapter.hpp"
#include "IntegerRangeTypeAdapter.hpp"

using FloatingPointTypeAdapter = rclcpp::TypeAdapter<rcl_interfaces::msg::FloatingPointRange, FloatingPointRange>;
using IntegerTypeAdapter = rclcpp::TypeAdapter<rcl_interfaces::msg::IntegerRange, IntegerRange>;

struct Parameter
{
  std::string name;
  unsigned char type;
  std::string description;
  std::string additional_constraints;
  bool read_only = false;
  bool dynamic_typing = false;
  FloatingPointRange floating_point_range;
  IntegerRange integer_range;
};

template<>
struct rclcpp::TypeAdapter<
   Parameter,
   rcl_interfaces::msg::Parameter
>
{
  using is_specialized = std::true_type;
  using custom_type = Parameter;
  using ros_message_type = rcl_interfaces::msg::Parameter;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.name = source.name;
    destination.type = source.type;
    destination.description = source.description;
    destination.additional_constraints = source.additional_constraints;
    destination.read_only = source.read_only;
    destination.dynamic_typing = source.dynamic_typing;
    FloatingPointTypeAdapter::convert_to_ros_message(source.floating_point_range, destination.floating_point_range);
    IntegerTypeAdapter::convert_to_ros_message(source.integer_range, destination.integer_range);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.name = source.name;
    destination.type = source.type;
    destination.description = source.description;
    destination.additional_constraints = source.additional_constraints;
    destination.read_only = source.read_only;
    destination.dynamic_typing = source.dynamic_typing;
    FloatingPointTypeAdapter::convert_to_custom(source.floating_point_range, destination.floating_point_range);
    IntegerTypeAdapter::convert_to_custom(source.integer_range, destination.integer_range);
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERDESCRIPTORTYPEADAPTER_HPP_

#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERTYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/parameter.hpp"
#include "rcl_interfaces/msg/parameter_value.hpp"

#include "ParameterValueTypeAdapter.hpp"

using ParameterValueTypeAdapter = rclcpp::TypeAdapter<rcl_interfaces::msg::ParameterValue, ParameterValue>;

struct Parameter
{
  std::string name;
  ParameterValue value;
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
    ParameterValueTypeAdapter::convert_to_ros_message(source.value, destination.value);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.name = source.name;
    ParameterValueTypeAdapter::convert_to_custom(source.value, destination.value);
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERTYPEADAPTER_HPP_

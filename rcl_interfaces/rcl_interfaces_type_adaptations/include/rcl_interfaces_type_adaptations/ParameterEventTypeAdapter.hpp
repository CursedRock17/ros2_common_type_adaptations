#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETEREVENTTYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETEREVENTTYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/parameter_event.hpp"
#include "rcl_interfaces/msg/parameter.hpp"
#include "ParameterTypeAdapter.hpp"
#include "builtin_interfaces/msg/time.hpp"

#include "builtin_interfaces_type_adaptations/TimeTypeAdapter.hpp"

using TimeTypeAdapter = rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>;
using ParameterTypeAdapter = rclcpp::TypeAdapter<Parameter, rcl_interfaces::msg::Parameter>

struct ParameterEvent
{
  Time stamp;
  std::string node;
  std::vector<Parameter> new_parameters;
  std::vector<Parameter> changed_parameters;
  std::vector<Parameter> deleted_parameters;
};

template<>
struct rclcpp::TypeAdapter<
   ParameterEvent,
   rcl_interfaces::msg::ParameterEvent
>
{
  using is_specialized = std::true_type;
  using custom_type = ParameterEvent;
  using ros_message_type = rcl_interfaces::msg::ParameterEvent;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.node = source.node;
    TimeTypeAdapter::convert_to_ros_message(source.stamp, destination.stamp);
    for (int i = 0; i < source.new_parameters.size(); i++)
    {
      ParameterTypeAdapter::convert_to_ros_message(
        source.new_parameters.at(i), destination.new_parameters[i]);
    }
    for (int i = 0; i < source.changed_parameters.size(); i++)
    {
      ParameterTypeAdapter::convert_to_ros_message(
        source.changed_parameters.at(i), destination.changed_parameters[i]);
    }
    for (int i = 0; i < source.deleted_parameters.size(); i++)
    {
      ParameterTypeAdapter::convert_to_ros_message(
        source.deleted_parameters.at(i), destination.deleted_parameters[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.node = source.node;
    TimeTypeAdapter::convert_to_custom(source.stamp, destination.stamp);
    for (int i = 0; i < sizeof(source.new_parameters)/sizeof(*source.new_parameters); i++)
    {
      ParameterTypeAdapter::convert_to_custom(
        source.new_parameters[i], destination.new_parameters.at(i));
    }
    for (int i = 0; i < sizeof(source.changed_parameters)/sizeof(*source.changed_parameters); i++)
    {
      ParameterTypeAdapter::convert_to_custom(
        source.changed_parameters[i], destination.changed_parameters.at(i));
    }
    for (int i = 0; i < sizeof(source.deleted_parameters)/sizeof(*source.deleted_parameters); i++)
    {
      ParameterTypeAdapter::convert_to_custom(
        source.deleted_parameters[i], destination.deleted_parameters.at(i));
    }
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETEREVENTTYPEADAPTER_HPP_

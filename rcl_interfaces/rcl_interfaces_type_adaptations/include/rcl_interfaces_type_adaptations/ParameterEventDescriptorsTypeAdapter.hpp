#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETEREVENTDESCRIPTORSTYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETEREVENTDESCRIPTORSTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/parameter_event_descriptors.hpp"
#include "rcl_interfaces/msg/parameter_descriptor.hpp"

#include "ParameterDescriptorTypeAdapter.hpp"

using ParameterDescriptorTypeAdapter = rclcpp::TypeAdapter<ParameterDescriptor, rcl_interfaces::msg::ParameterDescriptor>

struct ParameterEventDescriptors
{
  std::vector<Parameter> new_parameters;
  std::vector<Parameter> changed_parameters;
  std::vector<Parameter> deleted_parameters;
};

template<>
struct rclcpp::TypeAdapter<
   ParameterEventDescriptors,
   rcl_interfaces::msg::ParameterEventDescriptors
>
{
  using is_specialized = std::true_type;
  using custom_type = ParameterEventDescriptors;
  using ros_message_type = rcl_interfaces::msg::ParameterEventDescriptors;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    for (int i = 0; i < source.new_parameters.size(); i++)
    {
      ParameterDescriptorTypeAdapter::convert_to_ros_message(
        source.new_parameters.at(i), destination.new_parameters[i]);
    }
    for (int i = 0; i < source.changed_parameters.size(); i++)
    {
      ParameterDescriptorTypeAdapter::convert_to_ros_message(
        source.changed_parameters.at(i), destination.changed_parameters[i]);
    }
    for (int i = 0; i < source.deleted_parameters.size(); i++)
    {
      ParameterDescriptorTypeAdapter::convert_to_ros_message(
        source.deleted_parameters.at(i), destination.deleted_parameters[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    for (int i = 0; i < sizeof(source.new_parameters)/sizeof(*source.new_parameters); i++)
    {
      ParameterDescriptorTypeAdapter::convert_to_custom(
        source.new_parameters[i], destination.new_parameters.at(i));
    }
    for (int i = 0; i < sizeof(source.changed_parameters)/sizeof(*source.changed_parameters); i++)
    {
      ParameterDescriptorTypeAdapter::convert_to_custom(
        source.changed_parameters[i], destination.changed_parameters.at(i));
    }
    for (int i = 0; i < sizeof(source.deleted_parameters)/sizeof(*source.deleted_parameters); i++)
    {
      ParameterDescriptorTypeAdapter::convert_to_custom(
        source.deleted_parameters[i], destination.deleted_parameters.at(i));
    }
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETEREVENTDESCRIPTORSTYPEADAPTER_HPP_

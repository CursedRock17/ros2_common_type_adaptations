#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__LISTPARAMETERSRESULTTYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__LISTPARAMETERSRESULTTYPEADAPTER_HPP_

#include <string>
#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/list_parameters_result.hpp"

struct ListParametersResult
{
  std::vector<std::string> names;
  std::vector<std::string> prefixes;
};

template<>
struct rclcpp::TypeAdapter<
   ListParametersResult,
   rcl_interfaces::msg::ListParametersResult
>
{
  using is_specialized = std::true_type;
  using custom_type = ListParametersResult;
  using ros_message_type = rcl_interfaces::msg::ListParametersResult;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    for (int i = 0; i < source.names.size(); i++)
    {
      destination.names[i] = source.names.at(i);
    }
    for (int i = 0; i < source.prefixes.size(); i++)
    {
      destination.prefixes[i] = source.prefixes.at(i);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    for (int i = 0; i < source.names.size(); i++)
    {
      destination.names.at(i) = source.names[i];
    }
    for (int i = 0; i < source.prefixes.size(); i++)
    {
      destination.prefixes.at(i) = source.prefixes[i];
    }
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__LISTPARAMETERSRESULTTYPEADAPTER_HPP_

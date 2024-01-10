#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERVALUETYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERVALUETYPEADAPTER_HPP_

#include <string>
#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/parameter_value.hpp"

struct ParameterValue
{
  unsigned char type;
  bool bool_value;
  long long integer_value;
  double double_value;
  std::string string_value;
  std::vector<unsigned char> byte_array_value;
  std::vector<bool> bool_array_value;
  std::vector<long long> integer_array_value;
  std::vector<double> double_array_value;
  std::vector<std::string> string_array_value;
};

template<>
struct rclcpp::TypeAdapter<
   ParameterValue,
   rcl_interfaces::msg::ParameterValue
>
{
  using is_specialized = std::true_type;
  using custom_type = ParameterValue;
  using ros_message_type = rcl_interfaces::msg::ParameterValue;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.type = source.type;
    destination.bool_value = source.bool_value;
    destination.integer_value = source.integer_value;
    destination.double_value = source.double_value;
    destination.string_value = source.string_value;
    for (int i = 0; i < source.byte_array_value.size(); i++)
    {
      destination.byte_array_value[i] = source.byte_array_value.at(i);
    }
    for (int i = 0; i < source.bool_array_value.size(); i++)
    {
      destination.bool_array_value[i] = source.bool_array_value.at(i);
    }
    for (int i = 0; i < source.integer_array_value.size(); i++)
    {
      destination.integer_array_value[i] = source.integer_array_value.at(i);
    }
    for (int i = 0; i < source.double_array_value.size(); i++)
    {
      destination.double_array_value[i] = source.double_array_value.at(i);
    }
    for (int i = 0; i < source.string_array_value.size(); i++)
    {
      destination.string_array_value[i] = source.string_array_value.at(i);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.type = source.type;
    destination.bool_value = source.bool_value;
    destination.integer_value = source.integer_value;
    destination.double_value = source.double_value;
    destination.string_value = source.string_value;
    for (int i = 0; i < source.byte_array_values.size(); i++)
    {
      destination.byte_array_value.at(i) = source.byte_array_value[i];
    }
    for (int i = 0; i < source.bool_array_value.size(); i++)
    {
      destination.bool_array_value.at(i) = source.bool_array_value[i];
    }
    for (int i = 0; i < source.integer_array_value.size(); i++)
    {
      destination.integer_array_value.at(i) = source.integer_array_value[i];
    }
    for (int i = 0; i < source.double_array_value.size(); i++)
    {
      destination.double_array_value.at(i) = source.double_array_value[i];
    }
    for (int i = 0; i < string_array_value.size(); i++)
    {
      destination.string_array_value.at(i) = source.string_array_value[i];
    }
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERVALUETYPEADAPTER_HPP_

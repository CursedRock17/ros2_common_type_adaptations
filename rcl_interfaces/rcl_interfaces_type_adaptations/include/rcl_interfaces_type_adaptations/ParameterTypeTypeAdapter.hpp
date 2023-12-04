#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERTYPETYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERTYPETYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/parameter_type.hpp"

struct ParameterType
{
  constexpr static unsigned char PARAMETER_NOT_SET = 0;
  constexpr static unsigned char PARAMETER_BOOL = 1;
  constexpr static unsigned char PARAMETER_INTEGER = 2;
  constexpr static unsigned char PARAMETER_DOUBLE = 3;
  constexpr static unsigned char PARAMETER_STRING = 4;
  constexpr static unsigned char PARAMETER_BYTE_ARRAY = 5;
  constexpr static unsigned char PARAMETER_BOOL_ARRAY = 6;
  constexpr static unsigned char PARAMETER_INTEGER_ARRAY = 7;
  constexpr static unsigned char PARAMETER_DOUBLE_ARRAY = 8;
  constexpr static unsigned char PARAMETER_STRING_ARRAY = 9;
};

template<>
struct rclcpp::TypeAdapter<
   ParameterType,
   rcl_interfaces::msg::ParameterType
>
{
  using is_specialized = std::true_type;
  using custom_type = ParameterType;
  using ros_message_type = rcl_interfaces::msg::ParameterType;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__PARAMETERTYPETYPEADAPTER_HPP_

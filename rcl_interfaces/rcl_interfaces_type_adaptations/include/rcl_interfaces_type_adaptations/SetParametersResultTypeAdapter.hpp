#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__SETPARAMETERSRESULTTYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__SETPARAMETERSRESULTTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"

struct SetParametersResult
{
  bool successful;
  std::string reason;
};

template<>
struct rclcpp::TypeAdapter<
   SetParametersResult,
   rcl_interfaces::msg::SetParametersResult
>
{
  using is_specialized = std::true_type;
  using custom_type = SetParametersResult;
  using ros_message_type = rcl_interfaces::msg::SetParametersResult;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.successful = source.successful;
    destination.reason = source.reason;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.successful = source.successful;
    destination.reason = source.reason;
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__SETPARAMETERSRESULTTYPEADAPTER_HPP_

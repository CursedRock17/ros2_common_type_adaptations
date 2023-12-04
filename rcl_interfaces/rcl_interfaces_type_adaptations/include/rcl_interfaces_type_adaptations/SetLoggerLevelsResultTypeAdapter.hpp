#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__SETLOGGERLEVELSRESULTTYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__SETLOGGERLEVELSRESULTTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/set_logger_levels_result.hpp"

struct SetLoggerLevelsResult
{
  bool successful;
  std::string reason;
};

template<>
struct rclcpp::TypeAdapter<
   SetLoggerLevelsResult,
   rcl_interfaces::msg::SetLoggerLevelsResult
>
{
  using is_specialized = std::true_type;
  using custom_type = SetLoggerLevelsResult;
  using ros_message_type = rcl_interfaces::msg::SetLoggerLevelsResult;

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

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__SETLOGGERLEVELSRESULTTYPEADAPTER_HPP_

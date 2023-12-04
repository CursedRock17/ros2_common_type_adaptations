#ifndef RCL_INTERFACES_TYPE_ADAPTATIONS__LOGTYPEADAPTER_HPP_
#define RCL_INTERFACES_TYPE_ADAPTATIONS__LOGTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "rcl_interfaces/msg/log.hpp"
#include "builtin_interfaces/msg/time.hpp"

#include "builtin_interfaces_type_adaptations/TimeTypeAdapter.hpp"

using TimeTypeAdapter = rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time> ;

struct Log
{
  constexpr static unsigned char DEBUG = 10;
  constexpr static unsigned char INFO = 20;
  constexpr static unsigned char WARN = 30;
  constexpr static unsigned char ERROR = 40;
  constexpr static unsigned char FATAL = 50;

  Time stamp;
  unsigned char level;
  std::string name;
  std::string msg;
  std::string file;
  std::string function;
  unsigned long line;
};

template<>
struct rclcpp::TypeAdapter<
   Log,
   rcl_interfaces::msg::Log
>
{
  using is_specialized = std::true_type;
  using custom_type = Log;
  using ros_message_type = rcl_interfaces::msg::Log;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    TimeTypeAdapter::convert_to_ros_message(source.stamp, destination.stamp);
    destination.level = source.level;
    destination.name = source.name;
    destination.msg = source.msg;
    destination.file = source.file;
    destination.function = source.function;
    destination.line = source.line;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    TimeTypeAdapter::convert_to_custom(source.stamp, destination.stamp);
    destination.level = source.level;
    destination.name = source.name;
    destination.msg = source.msg;
    destination.file = source.file;
    destination.function = source.function;
    destination.line = source.line;
  }
};

#endif  // RCL_INTERFACES_TYPE_ADAPTATIONS__LOGTYPEADAPTER_HPP_

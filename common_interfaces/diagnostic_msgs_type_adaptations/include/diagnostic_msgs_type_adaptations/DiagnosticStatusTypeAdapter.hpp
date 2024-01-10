#ifndef DIAGNOSTIC_MSGS_TYPE_ADAPTATIONS__DIAGNOSTICSTATUSTYPEADAPTER_HPP_
#define DIAGNOSTIC_MSGS_TYPE_ADAPTATIONS__DIAGNOSTICSTATUSTYPEADAPTER_HPP_

#include <string>
#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "diagnostic_msgs/msg/diagnostic_status.hpp"
#include "diagnostic_msgs/msg/key_value.hpp"

#include "KeyValueTypeAdaptater.hpp"

struct DiagnosticStatus
{
  static constexpr unsigned char OK = 0;
  static constexpr unsigned char WARN = 1;
  static constexpr unsigned char ERROR = 2;
  static constexpr unsigned char STALE = 3;

  unsigned char level;
  std::string name;
  std::string message;
  std::string hardware_id;

  std::vector<KeyValue> values;
};

using KeyValueTypeAdaptater = rclcpp::TypeAdapter<KeyValue, diagnostic_msgs::msg::KeyValue>;

template<>
struct rclcpp::TypeAdapter<
   DiagnosticStatus,
   diagnostic_msgs::msg::DiagnosticStatus
>
{
  using is_specialized = std::true_type;
  using custom_type = DiagnosticStatus;
  using ros_message_type = diagnostic_msgs::msg::DiagnosticStatus;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.level = source.level;
    destination.name = source.name;
    destination.message = source.message;
    destination.hardware_id = source.hardware_id;

    for (int i = 0; i < source.values.size(); i++)
    {
      KeyValueTypeAdaptater::convert_to_ros_message(source.values.at(i), destination.values[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.level = source.level;
    destination.name = source.name;
    destination.message = source.message;
    destination.hardware_id = source.hardware_id;

    for (int i = 0; i < source.values.size(); i++)
    {
      KeyValueTypeAdaptater::convert_to_custom(source.values[i], destination.values.at(i));
    }
  }
};

#endif  // DIAGNOSTIC_MSGS_TYPE_ADAPTATIONS__DIAGNOSTICSTATUSTYPEADAPTER_HPP_

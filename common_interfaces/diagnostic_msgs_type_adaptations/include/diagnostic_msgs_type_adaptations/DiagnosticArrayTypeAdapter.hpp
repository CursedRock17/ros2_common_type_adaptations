#ifndef DIAGNOSTIC_MSGS_TYPE_ADAPTATIONS__DIAGNOSTICARRAYTYPEADAPTER_HPP_
#define DIAGNOSTIC_MSGS_TYPE_ADAPTATIONS__DIAGNOSTICARRAYTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "diagnostic_msgs/msg/diagnostic_status.hpp"
#include "diagnostic_msgs/msg/diagnostic_array.hpp"
#include "std_msgs/msg/header.hpp"

#include "DiagnosticStatusTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct DiagnosticArray
{
  Header header;
  std::vector<DiagnosticStatus> status;
};

using DiagnosticStatusTypeAdaptater = rclcpp::TypeAdapter<DiagnosticStatus, diagnostic_msgs::msg::DiagnosticStatus>;
using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;

template<>
struct rclcpp::TypeAdapter<
   DiagnosticStatus,
   diagnostic_msgs::msg::DiagnosticStatus
>
{
  using is_specialized = std::true_type;
  using custom_type = DiagnosticArray;
  using ros_message_type = diagnostic_msgs::msg::DiagnosticArray;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    for (int i = 0; i < source.status.size(); i++)
    {
      DiagnosticStatusTypeAdaptater::convert_to_ros_message(source.status.at(i), destination.status[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    for (int i = 0; i < sizeof(source.status)/sizeof(*source.status); i++)
    {
      DiagnosticStatusTypeAdaptater::convert_to_custom(source.status.[i], destination.status.at(i));
    }
  }
};

#endif  // DIAGNOSTIC_MSGS_TYPE_ADAPTATIONS__DIAGNOSTICARRAYTYPEADAPTER_HPP_

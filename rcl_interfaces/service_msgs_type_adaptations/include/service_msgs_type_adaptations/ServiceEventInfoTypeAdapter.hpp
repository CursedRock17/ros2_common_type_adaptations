#ifndef SERVICE_MSGS_TYPE_ADAPTATIONS__SERVICEEVENTINFOTYPEADAPTER_HPP_
#define SERVICE_MSGS_TYPE_ADAPTATIONS__SERVICEEVENTINFOTYPEADAPTER_HPP_

#include <array>

#include "rclcpp/type_adapter.hpp"
#include "service_msgs/msg/service_event_info.hpp"

#include "builtin_interfaces/msg/time.hpp"
#include "builtin_interfaces_type_adaptations/include/TimeTypeAdapter.hpp"

struct ServiceEventInfo
{
  static constexpr unsigned char REQUEST_SENT = 0;
  static constexpr unsigned char REQUEST_RECEIVED = 1;
  static constexpr unsigned char RESPONSE_SENT = 2;
  static constexpr unsigned char RESPONSE_RECEIVED = 3;

  unsigned char event_type;
  Time stamp;
  std::array<char, 16> client_gid;
  long long sequence_number;
};

template<>
struct rclcpp::TypeAdapter<
  ServiceEventInfo,
  service_msgs::msg::ServiceEventInfo
>
{
  using is_specialized = std::true_type;
  using custom_type = ServiceEventInfo;
  using ros_message_type = service_msgs::msg::ServiceEventInfo;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    source.event_type = destination.event_type;
    rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>::convert_to_ros_message(
      source.stamp, destination.stamp);
    source.sequence_number = destination.sequence_number;

    for (int i = 0; i < 16; i++ )
    {
      destination.client_gid[i] = source.client_gid.at(i);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    source.event_type = destination.event_type;
    rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>::convert_to_custom(
      source.stamp, destination.stamp);
    source.sequence_number = destination.sequence_number;

    for (int i = 0; i < 16; i++ )
    {
      source.client_gid.at(i) = destination.client_gid[i];
    }

  }
};

#endif  // SERVICE_MSGS_TYPE_ADAPTATIONS__SERVICEEVENTINFOTYPEADAPTER_HPP_

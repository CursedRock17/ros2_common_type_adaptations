#ifndef STD_MSGS_TYPE_ADAPTATIONS__HEADERTYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__HEADERTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/header.hpp"

#include "builtin_interfaces/msg/time.hpp"
#include "builtin_interfaces_type_adaptations/include/TimeTypeAdapter.hpp"

struct Header
{
  builtin_interfaces::msg::Time stamp;
  std::string frame_id;
};

template<>
struct rclcpp::TypeAdapter<
   Header,
   std_msgs::msg::Header
>
{
  using is_specialized = std::true_type;
  using custom_type = Header;
  using ros_message_type = std_msgs::msg::Header;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>::convert_to_ros_message(source.stamp, destination.stamp);
    destination.frame_id = source.frame_id;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>::convert_to_custom(source.stamp, destination.stamp);
    destination.frame_id = source.frame_id;
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__HEADERTYPEADAPTER_HPP_

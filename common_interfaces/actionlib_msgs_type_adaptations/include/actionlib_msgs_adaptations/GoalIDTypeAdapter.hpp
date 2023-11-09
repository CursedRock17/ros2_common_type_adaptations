#ifndef ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALIDTYPEADAPTER_HPP_
#define ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALIDTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "actionlib_msgs/msg/goal_id.hpp"
#include "builtin_interfaces/msg/time.hpp"

#include "builtin_interfaces_type_adaptations/include/TimeTypeAdapter.hpp"

struct GoalID
{
  Time stamp;
  std::string id;
};

using TimeAdapter = rclcpp::TypeAdapter<builtin_interfaces::msg::Time, Time>;

template<>
struct rclcpp::TypeAdapter<
   GoalID,
   actionlib_msgs::msg::GoalID
>
{
  using is_specialized = std::true_type;
  using custom_type = GoalID;
  using ros_message_type = actionlib_msgs::msg::GoalID;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    TimeAdapter::convert_to_ros_message(source.stamp, destination.stamp);
    destination.id = source.id;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    TimeAdapter::convert_to_custom(source.stamp, destination.stamp);
    destination.id = source.id;
  }
};

#endif  // ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALIDTYPEADAPTER_HPP_

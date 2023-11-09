#ifndef ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALSTATUSTYPEADAPTER_HPP_
#define ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALSTATUSTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "actionlib_msgs/msg/goal_id.hpp"
#include "actionlib_msgs/msg/goal_status.hpp"

#include "GoalIDTypeAdapter.hpp"

struct GoalStatus
{
  GoalID goal_id;
  unsigned char status;

  static constexpr unsigned char PENDING = 0;
  static constexpr unsigned char ACTIVE = 1;
  static constexpr unsigned char PREEMPTED = 2;
  static constexpr unsigned char SUCCEEDED= 3;
  static constexpr unsigned char ABORTED = 4;
  static constexpr unsigned char REJECTED = 5;
  static constexpr unsigned char PREEMPTING = 6;
  static constexpr unsigned char RECALLING = 7;
  static constexpr unsigned char RECALLED = 8;
  static constexpr unsigned char LOST = 9;

  std::string text;
};

using GoalIDAdapter = rclcpp::TypeAdapter<actionlib_msgs::msg::GoalID, GoalID>;

template<>
struct rclcpp::TypeAdapter<
   GoalStatus,
   actionlib_msgs::msg::GoalStatus
>
{
  using is_specialized = std::true_type;
  using custom_type = GoalStatus;
  using ros_message_type = actionlib_msgs::msg::GoalStatus;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    GoalIDAdapter::convert_to_ros_message(source.goal_id, destination.goal_id);
    destination.status = source.status;
    destination.text = source.text;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    GoalIDAdapter::convert_to_custom(source.goal_id, destination.goal_id);
    destination.status = source.status;
    destination.text = source.text;
  }
};

#endif  // ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALSTATUSTYPEADAPTER_HPP_

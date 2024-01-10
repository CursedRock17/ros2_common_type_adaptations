#ifndef ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALSTATUSARRAYTYPEADAPTER_HPP_
#define ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALSTATUSARRAYTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "actionlib_msgs/msg/goal_status.hpp"
#include "std_msgs/msg/header.hpp"

#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"
#include "GoalStatusTypeAdapter.hpp"

struct GoalStatusArray
{
  Header header;
  std::vector<GoalStatus> status_list;
};

using GoalStatusAdapter = rclcpp::TypeAdapter<actionlib_msgs::msg::GoalStatus, GoalStatus>;
using HeaderAdapter = rclcpp::TypeAdapter<std_msgs::msg::Header, Header>;

template<>
struct rclcpp::TypeAdapter<
   GoalStatusArray,
   actionlib_msgs::msg::GoalStatusArray
>
{
  using is_specialized = std::true_type;
  using custom_type = GoalStatusArray;
  using ros_message_type = actionlib_msgs::msg::GoalStatusArray;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    for (int i = 0; i < source.status_list.size(); i++)
    {
      GoalStatusAdapter::convert_to_ros_message(source.status_list.at(i), destination.status_list[i]);
    }
    HeaderAdapter::convert_to_ros_message(source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    for (int i = 0; i < source.status_list.size(); i++)
    {
      GoalStatusAdapter::convert_to_custom(source.status_list[i], destination.status_list.at(i));
    }
    HeaderAdapter::convert_to_custom(source.header, destination.header);
  }
};

#endif  // ACTIONLIB_MSGS_TYPE_ADAPTATIONS__GOALSTATUSARRAYTYPEADAPTER_HPP_

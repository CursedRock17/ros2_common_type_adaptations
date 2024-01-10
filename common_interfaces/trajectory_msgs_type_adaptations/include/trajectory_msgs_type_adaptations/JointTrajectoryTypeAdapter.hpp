#ifndef TRAJECTORY_MSGS_TYPE_ADAPTATIONS__JOINTTRAJECTORYTYPEADAPTER_HPP_
#define TRAJECTORY_MSGS_TYPE_ADAPTATIONS__JOINTTRAJECTORYTYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "rclcpp/type_adapter.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "std_msgs/msg/header.hpp"

#include "JointTrajectoryPointTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct JointTrajectory
{
  Header header;
  std::vector<std::string> joint_names;
  std::vector<JointTrajectoryPoint> points;
};

using JointTrajectoryPointAdapter =
  rclcpp::TypeAdapter<JointTrajectoryPoint, trajectory_msgs::msg::JointTrajectoryPoint>;
using HeaderAdapter =
  rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;

template<>
struct rclcpp::TypeAdapter<
   JointTrajectory,
   trajectory_msgs::msg::JointTrajectory
>
{
  using is_specialized = std::true_type;
  using custom_type = JointTrajectory;
  using ros_message_type = trajectory_msgs::msg::JointTrajectory;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderAdapter::convert_to_ros_message(source.header, destination.header);
    for (int i = 0; i < source.joint_names.size(); i++)
    {
      destination.joint_names[i] = source.joint_names.at(i);
    }
    for (int i = 0; i < source.points.size(); i++)
    {
      JointTrajectoryPointAdapter::convert_to_ros_message(source.points[i], destination.points.at(i));
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderAdapter::convert_to_custom(source.header, destination.header);
    for (int i = 0; i < source.joint_names.size(); i++)
    {
      destination.joint_names.at(i) = source.joint_names[i];
    }
    for (int i = 0; i < source.points.size(); i++)
    {
      JointTrajectoryPointAdapter::convert_to_custom(source.points.at(i), destination.points[i]);
    }
  }
};

#endif  // TRAJECTORY_MSGS_TYPE_ADAPTATIONS__JOINTTRAJECTORYTYPEADAPTER_HPP_

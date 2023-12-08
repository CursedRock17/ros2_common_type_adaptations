#ifndef TRAJECTORY_MSGS_TYPE_ADAPTATIONS__JOINTTRAJECTORYPOINTTYPEADAPTER_HPP_
#define TRAJECTORY_MSGS_TYPE_ADAPTATIONS__JOINTTRAJECTORYPOINTTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "builtin_interfaces/msg/duration.hpp"

#include "builtin_interfaces_type_adaptations/include/DurationTypeAdapter.hpp"

struct JointTrajectoryPoint
{
  std::vector<double> positions;
  std::vector<double> velocities;
  std::vector<double> accelerations;
  std::vector<double> effort;
  Duration time_from_start;
};

using DurationAdapter = rclcpp::TypeAdapter<builtin_interfaces::msg::Duration, Duration>;

template<>
struct rclcpp::TypeAdapter<
   JointTrajectoryPoint,
   trajectory_msgs::msg::JointTrajectoryPoint
>
{
  using is_specialized = std::true_type;
  using custom_type = JointTrajectoryPoint;
  using ros_message_type = trajectory_msgs::msg::JointTrajectoryPoint;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    for (int i = 0; i < source.positions.size(); i++)
    {
      destination.positions[i] = source.positions.at(i);
    }
    for (int i = 0; i < source.velocities.size(); i++)
    {
      destination.velocities[i] = source.velocities.at(i);
    }
    for (int i = 0; i < source.accelerations.size(); i++)
    {
      destination.accelerations[i] = source.accelerations.at(i);
    }
    for (int i = 0; i < source.effort.size(); i++)
    {
      destination.effort[i] = source.effort.at(i);
    }
    DurationAdapter::convert_to_ros_message(source.time_from_start, destination.time_from_start);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    for (int i = 0; i < sizeof(source.positions)/sizeof(*source.positions); i++)
    {
      destination.positions.at(i) = source.positions[i];
    }
    for (int i = 0; i < sizeof(source.velocities)/sizeof(*source.velocities); i++)
    {
      destination.velocities.at(i) = source.velocities[i];
    }
    for (int i = 0; i < sizeof(source.accelerations)/sizeof(*source.accelerations); i++)
    {
      destination.accelerations.at(i) = source.accelerations[i];
    }
    for (int i = 0; i < sizeof(source.effort)/sizeof(*source.effort); i++)
    {
      destination.effort.at(i) = source.effort[i];
    }
    DurationAdapter::convert_to_custom(source.time_from_start, destination.time_from_start);
  }
};

#endif  // TRAJECTORY_MSGS_TYPE_ADAPTATIONS__JOINTTRAJECTORYPOINTTYPEADAPTER_HPP_

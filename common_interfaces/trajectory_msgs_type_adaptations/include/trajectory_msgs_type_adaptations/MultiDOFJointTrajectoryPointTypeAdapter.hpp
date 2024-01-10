#ifndef TRAJECTORY_MSGS_TYPE_ADAPTATIONS__MULTIDOFJOINTTRAJECTORYPOINTTYPEADAPTER_HPP_
#define TRAJECTORY_MSGS_TYPE_ADAPTATIONS__MULTIDOFJOINTTRAJECTORYPOINTTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "trajectory_msgs/msg/multi_dof_joint_trajectory_point.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/transform.hpp"

#include "builtin_interfaces_type_adaptations/include/DurationTypeAdapter.hpp"
#include "geometry_msgs_type_adaptations/include/TwistTypeAdapter.hpp"
#include "geometry_msgs_type_adaptations/include/TransformTypeAdapter.hpp"

struct MultiDOFJointTrajectoryPoint
{
  std::vector<Transform> transforms;
  std::vector<Twist> velocities;
  std::vector<Twist> accelerations;
  Duration time_from_start;
};

using DurationAdapter = rclcpp::TypeAdapter<Duration, builtin_interfaces::msg::Duration>;
using TransformAdapter = rclcpp::TypeAdapter<Transform, geometry_msgs::msg::Transform>;
using TwistAdapter = rclcpp::TypeAdapter<Twist, geometry_msgs::msg::Twist>;

template<>
struct rclcpp::TypeAdapter<
   MultiDOFJointTrajectoryPoint,
   trajectory_msgs::msg::MultiDOFJointTrajectoryPoint
>
{
  using is_specialized = std::true_type;
  using custom_type = MultiDOFJointTrajectoryPoint;
  using ros_message_type = trajectory_msgs::msg::MultiDOFJointTrajectoryPoint;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    for (int i = 0; i < source.transforms.size(); i++)
    {
      TransformAdapter::convert_to_ros_message(source.transforms.at(i), destination.transforms[i]);
    }
    for (int i = 0; i < source.velocities.size(); i++)
    {
      TwistAdapter::convert_to_ros_message(source.velocities.at(i), destination.velocities[i]);
    }
    for (int i = 0; i < source.accelerations.size(); i++)
    {
      TwistAdapter::convert_to_ros_message(source.accelerations.at(i), destination.accelerations[i]);
    }
    DurationAdapter::convert_to_ros_message(source.time_from_start, destination.time_from_start);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    for (int i = 0; i < source.transforms.size(); i++)
    {
      TransformAdapter::convert_to_custom(source.transforms[i], destination.transforms.at(i));
    }
    for (int i = 0; i < source.velocities.size(); i++)
    {
      TwistAdapter::convert_to_custom(source.velocities[i], destination.velocities.at(i));
    }
    for (int i = 0; i < source.accelerations.size(); i++)
    {
      TwistAdapter::convert_to_custom(source.accelerations[i], destination.accelerations.at(i));
    }
    DurationAdapter::convert_to_custom(source.time_from_start, destination.time_from_start);
  }
};

#endif  // TRAJECTORY_MSGS_TYPE_ADAPTATIONS__MULTIDOFJOINTTRAJECTORYPOINTTYPEADAPTER_HPP_

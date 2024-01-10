#ifndef TRAJECTORY_MSGS_TYPE_ADAPTATIONS__MULTIDOFJOINTTRAJECTORYTYPEADAPTER_HPP_
#define TRAJECTORY_MSGS_TYPE_ADAPTATIONS__MULTIDOFJOINTTRAJECTORYTYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "rclcpp/type_adapter.hpp"
#include "trajectory_msgs/msg/multi_dof_joint_trajectory.hpp"
#include "trajectory_msgs/msg/multi_dof_joint_trajectory_point.hpp"
#include "std_msgs/msg/header.hpp"

#include "MultiDOFJointTrajectoryPointTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct MultiDOFJointTrajectory
{
  Header header;
  std::vector<std::string> joint_names;
  std::vector<MultiDOFJointTrajectoryPoint> points;
};

using MultiDOFJointTrajectoryPointAdapter =
  rclcpp::TypeAdapter<MultiDOFJointTrajectoryPoint, trajectory_msgs::msg::MultiDOFJointTrajectoryPoint>;
using HeaderAdapter =
  rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;

template<>
struct rclcpp::TypeAdapter<
   MultiDOFJointTrajectory,
   trajectory_msgs::msg::MultiDOFJointTrajectory
>
{
  using is_specialized = std::true_type;
  using custom_type = MultiDOFJointTrajectory;
  using ros_message_type = trajectory_msgs::msg::MultiDOFJointTrajectory;

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
      MultiDOFJointTrajectoryPointAdapter::convert_to_ros_message(destination.points[i], source.points.at(i));
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
      MultiDOFJointTrajectoryPointAdapter::convert_to_custom(destination.points.at(i), source.points[i]);
    }
  }
};

#endif  // TRAJECTORY_MSGS_TYPE_ADAPTATIONS__MULTIDOFJOINTTRAJECTORYTYPEADAPTER_HPP_

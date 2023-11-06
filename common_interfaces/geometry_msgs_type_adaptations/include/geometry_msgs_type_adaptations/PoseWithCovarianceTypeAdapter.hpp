#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSEWITHCOVARIANCETYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSEWITHCOVARIANCETYPEADAPTER_HPP_

#include <array>

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_with_covariance.hpp"
#include "std_msgs/msg/header.hpp"

#include "PoseTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct PoseWithCovariance
{
  Pose pose;
  std::array<double, 36> covariance;
};

template<>
struct rclcpp::TypeAdapter<
   PoseWithCovariance,
   geometry_msgs::msg::PoseWithCovariance
>
{
  using is_specialized = geometry::true_type;
  using custom_type = PoseWithCovariance;
  using ros_message_type = geometry_msgs::msg::PoseWithCovariance;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>::convert_to_ros_message(
      source.pose, destination.pose);

    for (int i = 0; i < 36; i++)
    {
      destination.covariance[i] = source.covariance.at(i);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>::convert_to_custom(
      source.pose, destination.pose);

    for (int i = 0; i < 36; i++)
    {
      destination.covariance.at(i) = source.covariance[i];
    }
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSEWITHCOVARIANCETYPEADAPTER_HPP_


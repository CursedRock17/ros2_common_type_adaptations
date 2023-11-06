#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTWITHCOVARIANCETYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTWITHCOVARIANCETYPEADAPTER_HPP_

#include <array>

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/twist_with_covariance.hpp"
#include "std_msgs/msg/header.hpp"

#include "TwistTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct TwistWithCovariance
{
  Twist twist;
  std::array<double, 36> covariance;
};

template<>
struct rclcpp::TypeAdapter<
   TwistWithCovariance,
   geometry_msgs::msg::TwistWithCovariance
>
{
  using is_specialized = geometry::true_type;
  using custom_type = TwistWithCovariance;
  using ros_message_type = geometry_msgs::msg::TwistWithCovariance;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Twist, geometry_msgs::msg::Twist>::convert_to_ros_message(
      source.twist, destination.twist);

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
    rclcpp::TypeAdapter<Twist, geometry_msgs::msg::Twist>::convert_to_custom(
      source.twist, destination.twist);

    for (int i = 0; i < 36; i++)
    {
      destination.covariance.at(i) = source.covariance[i];
    }
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__TWISTWITHCOVARIANCETYPEADAPTER_HPP_

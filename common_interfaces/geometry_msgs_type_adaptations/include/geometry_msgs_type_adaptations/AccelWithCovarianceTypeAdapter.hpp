#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELWITHCOVARIANCETYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELWITHCOVARIANCETYPEADAPTER_HPP_

#include <array>

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/accel.hpp"
#include "geometry_msgs/msg/accel_with_covariance.hpp"
#include "std_msgs/msg/header.hpp"

#include "AccelTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct AccelWithCovariance
{
  Accel accel;
  std::array<double, 36> covariance;
};

template<>
struct rclcpp::TypeAdapter<
   AccelWithCovariance,
   geometry_msgs::msg::AccelWithCovariance
>
{
  using is_specialized = geometry::true_type;
  using custom_type = AccelWithCovariance;
  using ros_message_type = geometry_msgs::msg::AccelWithCovariance;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Accel, geometry_msgs::msg::Accel>::convert_to_ros_message(
      source.accel, destination.accel);

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
    rclcpp::TypeAdapter<Accel, geometry_msgs::msg::Accel>::convert_to_custom(
      source.accel, destination.accel);

    for (int i = 0; i < 36; i++)
    {
      destination.covariance.at(i) = source.covariance[i];
    }
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELWITHCOVARIANCETYPEADAPTER_HPP_

#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELWITHCOVARIANCESTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELWITHCOVARIANCESTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/accel.hpp"
#include "geometry_msgs/msg/accel_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "AccelWithCovarianceTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct AccelWithCovarianceStamped
{
  AccelWithCovariance accel;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   AccelWithCovarianceStamped,
   geometry_msgs::msg::AccelWithCovarianceStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = AccelWithCovarianceStamped;
  using ros_message_type = geometry_msgs::msg::AccelWithCovarianceStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<AccelWithCovariance, geometry_msgs::msg::AccelWithCovariance>::
      convert_to_ros_message(source.accel, destination.accel);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::
      convert_to_ros_message(source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<AccelWithCovariance, geometry_msgs::msg::AccelWithCovariance>::
      convert_to_custom(source.accel, destination.accel);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::
      convert_to_custom(source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__ACCELWITHCOVARIANCESTAMPEDTYPEADAPTER_HPP_

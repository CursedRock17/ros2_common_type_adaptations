#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSEWITHCOVARIANCESTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSEWITHCOVARIANCESTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "PoseWithCovarianceTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct PoseWithCovarianceStamped
{
  PoseWithCovariance pose;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   PoseWithCovarianceStamped,
   geometry_msgs::msg::PoseWithCovarianceStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = PoseWithCovarianceStamped;
  using ros_message_type = geometry_msgs::msg::PoseWithCovarianceStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<PoseWithCovariance, geometry_msgs::msg::PoseWithCovariance>::
      convert_to_ros_message(source.pose, destination.pose);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::
      convert_to_ros_message(source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<PoseWithCovariance, geometry_msgs::msg::PoseWithCovariance>::
      convert_to_custom(source.pose, destination.pose);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::
      convert_to_custom(source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSEWITHCOVARIANCESTAMPEDTYPEADAPTER_HPP_

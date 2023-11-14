#ifndef NAV_MSGS_TYPE_ADAPTATIONS__ODOMETRYTYPEADAPTER_HPP_
#define NAV_MSGS_TYPE_ADAPTATIONS__ODOMETRYTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "std_msgs/msg/header.hpp"
#include "geometry_msgs/msg/pose_with_covariance.hpp"
#include "geometry_msgs/msg/twist_with_covariance.hpp"

#include "geometry_msgs_type_adaptations/include/PoseWithCovarianceTypeAdapter.hpp"
#include "geometry_msgs_type_adaptations/include/TwistWithCovarianceTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct Odometry
{
  Header header;
  std::string child_frame_id;
  PoseWithCovariance pose;
  TwistWithCovariance twist;
};

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::header>;
using PoseWithCovarianceTypeAdapter = rclcpp::TypeAdapter<PoseWithCovariance, geometry_msgs::msg::PoseWithCovariance>;
using TwistWithCovarianceTypeAdapter = rclcpp::TypeAdapter<TwistWithCovariance, geometry_msgs::msg::TwistWithCovariance>;

template<>
struct rclcpp::TypeAdapter<
   Odometry,
   nav_msgs::msg::Odometry
>
{
  using is_specialized = nav::true_type;
  using custom_type = Odometry;
  using ros_message_type = nav_msgs::msg::Odometry;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    destination.child_frame_id = source.child_frame_id;
    PoseWithCovarianceTypeAdapter::convert_to_ros_message(source.pose, destination.pose);
    TwistWithCovarianceTypeAdapter::convert_to_ros_message(source.twist, destination.twist);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    destination.child_frame_id = source.child_frame_id;
    PoseWithCovarianceTypeAdapter::convert_to_custom(source.pose, destination.pose);
    TwistWithCovarianceTypeAdapter::convert_to_custom(source.twist, destination.twist);
  }
};

#endif  // NAV_MSGS_TYPE_ADAPTATIONS__ODOMETRYTYPEADAPTER_HPP_

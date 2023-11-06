#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSE2DTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSE2DTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/pose2d.hpp"

struct Pose2D
{
  double x;
  double y;
  double theta;
};

template<>
struct rclcpp::TypeAdapter<
   Pose2D,
   geometry_msgs::msg::Pose2D
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Pose2D;
  using ros_message_type = geometry_msgs::msg::Pose2D;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.x = source.x;
    destination.y = source.y;
    destination.theta = source.theta;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.x = source.x;
    destination.y = source.y;
    destination.theta = source.theta;
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POSE2DTYPEADAPTER_HPP_

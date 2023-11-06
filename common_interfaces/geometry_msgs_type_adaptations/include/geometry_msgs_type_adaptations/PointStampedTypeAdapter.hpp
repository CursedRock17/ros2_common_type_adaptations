#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POINTSTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POINTSTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "PointTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct PointStamped
{
  Point point;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   PointStamped,
   geometry_msgs::msg::PointStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = PointStamped;
  using ros_message_type = geometry_msgs::msg::PointStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Point, geometry_msgs::msg::Point>::convert_to_ros_message(
      source.point, destination.point);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Point, geometry_msgs::msg::Point>::convert_to_custom(
      source.point, destination.point);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POINTSTAMPEDTYPEADAPTER_HPP_

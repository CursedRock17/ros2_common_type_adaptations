#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POLYGONSTAMPEDTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POLYGONSTAMPEDTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/polygon.hpp"
#include "geometry_msgs/msg/polygon_stamped.hpp"
#include "std_msgs/msg/header.hpp"

#include "PolygonTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct PolygonStamped
{
  Polygon polygon;
  Header header;
};

template<>
struct rclcpp::TypeAdapter<
   PolygonStamped,
   geometry_msgs::msg::PolygonStamped
>
{
  using is_specialized = geometry::true_type;
  using custom_type = PolygonStamped;
  using ros_message_type = geometry_msgs::msg::PolygonStamped;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Polygon, geometry_msgs::msg::Polygon>::convert_to_ros_message(
      source.polygon, destination.polygon);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_ros_message(
      source.header, destination.header);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Polygon, geometry_msgs::msg::Polygon>::convert_to_custom(
      source.polygon, destination.polygon);
    rclcpp::TypeAdapter<Header, std_msgs::msg::Header>::convert_to_custom(
      source.header, destination.header);
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POLYGONSTAMPEDTYPEADAPTER_HPP_

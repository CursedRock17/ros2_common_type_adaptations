#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__POLYGONTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__POLYGONTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/point32.hpp"
#include "geometry_msgs/msg/polygon.hpp"

#include "Point32TypeAdapter.hpp"

template<>
struct rclcpp::TypeAdapter<
   std::vector<Point32>,
   geometry_msgs::msg::Polygon
>
{
  using is_specialized = geometry::true_type;
  using custom_type = std::vector<Point32>;
  using ros_message_type = geometry_msgs::msg::Polygon;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    for (int i = 0; i < source.points.size(); i++)
    {
      destination.points[i] = source.points.at(i);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    for (int i  = 0; i < source.points.size(); i++)
    {
      destination.points.at(i) = source.points[i];
    }
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__POLYGONTYPEADAPTER_HPP_

#ifndef SHAPE_MSGS_TYPE_ADAPTATIONS__PLANETYPEADAPTER_HPP_
#define SHAPE_MSGS_TYPE_ADAPTATIONS__PLANETYPEADAPTER_HPP_

#include <array>

#include "rclcpp/type_adapter.hpp"
#include "shape_msgs/msg/plane.hpp"

template<>
struct rclcpp::TypeAdapter<
   std::array<double, 4>,
   shape_msgs::msg::Plane
>
{
  using is_specialized = std::true_type;
  using custom_type = std::array<double, 4>;
  using ros_message_type = shape_msgs::msg::Plane;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.vertex_indices[0] = source.vertex_indices.at(0);
    destination.vertex_indices[1] = source.vertex_indices.at(1);
    destination.vertex_indices[2] = source.vertex_indices.at(2);
    destination.vertex_indices[3] = source.vertex_indices.at(3);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.vertex_indices.at(0) = source.vertex_indices[0];
    destination.vertex_indices.at(1) = source.vertex_indices[1];
    destination.vertex_indices.at(2) = source.vertex_indices[2];
    destination.vertex_indices.at(3) = source.vertex_indices[3];
  }
};

#endif  // SHAPE_MSGS_TYPE_ADAPTATIONS__PLANETYPEADAPTER_HPP_

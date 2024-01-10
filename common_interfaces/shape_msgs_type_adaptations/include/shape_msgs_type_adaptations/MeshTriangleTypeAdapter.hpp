#ifndef SHAPE_MSGS_TYPE_ADAPTATIONS__MESHTRIANGLETYPEADAPTER_HPP_
#define SHAPE_MSGS_TYPE_ADAPTATIONS__MESHTRIANGLETYPEADAPTER_HPP_

#include <array>

#include "rclcpp/type_adapter.hpp"
#include "shape_msgs/msg/mesh_triangle.hpp"

template<>
struct rclcpp::TypeAdapter<
   std::array<unsigned long, 3>,
   shape_msgs::msg::MeshTriangle
>
{
  using is_specialized = std::true_type;
  using custom_type = std::array<unsigned long, 3>;
  using ros_message_type = shape_msgs::msg::MeshTriangle;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.vertex_indices[0] = source.vertex_indices.at(0);
    destination.vertex_indices[1] = source.vertex_indices.at(1);
    destination.vertex_indices[2] = source.vertex_indices.at(2);
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
  }
};

#endif  // SHAPE_MSGS_TYPE_ADAPTATIONS__MESHTRIANGLETYPEADAPTER_HPP_

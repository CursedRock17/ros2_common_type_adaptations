#ifndef SHAPE_MSGS_TYPE_ADAPTATIONS__MESHTYPEADAPTER_HPP_
#define SHAPE_MSGS_TYPE_ADAPTATIONS__MESHTYPEADAPTER_HPP_

#include <array>
#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "shape_msgs/msg/mesh.hpp"
#include "shape_msgs/msg/mesh_triangle.hpp"
#include "geometry_msgs/msg/point.hpp"

#include "MeshTriangleTypeAdapter.hpp"
#include "geometry_msgs_type_adaptations/include/PointTypeAdapter.hpp"

struct Mesh
{
  std::vector<std::array<unsigned long, 3>> triangles;
  std::vector<Point> vertices;
};

template<>
struct rclcpp::TypeAdapter<
   Mesh,
   shape_msgs::msg::Mesh
>
{
  using is_specialized = std::true_type;
  using custom_type = Mesh;
  using ros_message_type = shape_msgs::msg::Mesh;

  using MeshTriangleAdapter = rclcpp::TypeAdapter<std::array<unsigned long, 3>,
    shape_msgs::msg::MeshTriangle>;
  using PointAdapter = rclcpp::TypeAdapter<Point, geometry_msgs::msg::Point>;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    for (int i = 0; i < source.triangles.size(); i++)
    {
      MeshTriangleAdapter::convert_to_ros_message(source.triangles.at(i), destination.triangles[i]);
    }
    for (int i = 0; i < source.vertices.size(); i++)
    {
      PointAdapter::convert_to_ros_message(source.vertices.at(i), destination.vertices[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    for (int i = 0; i < source.triangles.size(); i++)
    {
      MeshTriangleAdapter::convert_to_custom(source.triangles[i], destination.triangles.at(i));
    }
    for (int i = 0; i < source.vertices.size(); i++)
    {
      PointAdapter::convert_to_custom(source.vertices[i], destination.triangles.at(i));
    }
  }
};

#endif  // SHAPE_MSGS_TYPE_ADAPTATIONS__MESHTYPEADAPTER_HPP_

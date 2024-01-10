#ifndef SHAPE_MSGS_TYPE_ADAPTATIONS__SOLIDPRIMITIVETYPEADAPTER_HPP_
#define SHAPE_MSGS_TYPE_ADAPTATIONS__SOLIDPRIMITIVETYPEADAPTER_HPP_

#include <array>

#include "rclcpp/type_adapter.hpp"
#include "shape_msgs/msg/mesh_triangle.hpp"
#include "geometry_msgs/msg/polygon.hpp"

#include "geometry_msgs_type_adaptations/include/PolygonTypeAdapter.hpp"

struct SolidPrimitive
{
  static constexpr unsigned char BOX = 1;
  static constexpr unsigned char SPHERE = 2;
  static constexpr unsigned char CYLINDER = 3;
  static constexpr unsigned char CONE = 4;
  static constexpr unsigned char PRISM = 5;

  unsigned char type;

  std::array<double, 3> dimensions;

  static constexpr unsigned char BOX_X = 0;
  static constexpr unsigned char BOX_Y = 0;
  static constexpr unsigned char BOX_Z = 0;

  static constexpr unsigned char SPHERE_RADIUS = 0;

  static constexpr unsigned char CYLINDER_HEIGHT = 0;
  static constexpr unsigned char CYLINDER_RADIUS = 1;

  static constexpr unsigned char CONE_HEIGHT = 0;
  static constexpr unsigned char CONE_RADIUS = 1;

  static constexpr unsigned char PRISM_HEIGHT = 0;
  Polygon polygon;
};

template<>
struct rclcpp::TypeAdapter<
   SolidPrimitive,
   shape_msgs::msg::SolidPrimitive
>
{
  using is_specialized = std::true_type;
  using custom_type = SolidPrimitive;
  using ros_message_type = shape_msgs::msg::SolidPrimitive;

  using PolygonAdapter = rclcpp::TypeAdapter<Polygon, geometry_msgs::msg::Polygon>;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.type = source.type;
    for (int i = 0; i < source.dimensions.size(); i++)
    {
      destination.dimensions[i] = source.dimensions.at(i);
    }
    PolygonAdapter::convert_to_ros_message(source.polygon, destination.polygon);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.type = source.type;
    for (int i = 0; i < source.dimensions.size(); i++)
    {
      destination.dimensions.at(i) = source.dimensions[i];
    }
    PolygonAdapter::convert_to_custom(source.polygon, destination.polygon);
  }
};

#endif  // SHAPE_MSGS_TYPE_ADAPTATIONS__SOLIDPRIMITIVETYPEADAPTER_HPP_

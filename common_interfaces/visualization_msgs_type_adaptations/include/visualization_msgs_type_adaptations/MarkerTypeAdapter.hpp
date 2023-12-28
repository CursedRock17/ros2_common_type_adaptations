#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MARKERTYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MARKERTYPEADAPTER_HPP_

#include <cinttypes>
#include <vector>
#include <string>

#include "visualization_msgs/msg/marker.hpp"

#include "visualization_msgs/msg/mesh_file.hpp"
#include "visualization_msgs/msg/uv_coordinate.hpp"
#include "MeshFileTypeAdapter.hpp"
#include "UVCoordinateTypeAdapter.hpp"

#include "rclcpp/type_adapter.hpp"

#include "std_msgs/msg/header.hpp"
#include "std_msgs/msg/color_rgba.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/ColorRGBATypeAdapter.hpp"

#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs_type_adaptations/include/PointTypeAdapter.hpp"
#include "geometry_msgs_type_adaptations/include/Vector3TypeAdapter.hpp"

#include "builtin_interfaces/msg/duration.hpp"
#include "builtin_interfaces_type_adaptations/include/DurationTypeAdapter.hpp"

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;
using ColorRGBATypeAdapter = rclcpp::TypeAdapter<ColorRGBA, std_msgs::msg::ColorRGBA>;
using PointTypeAdapter = rclcpp::TypeAdapter<Point, geometry_msgs::msg::Point>;
using PoseTypeAdapter = rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>;
using Vector3TypeAdapter = rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>;
using DurationTypeAdapter = rclcpp::TypeAdapter<Duration, builtin_interfaces::msg::Duration>;

struct Marker
{
  constexpr static long ARROW=0;
  constexpr static long CUBE=1;
  constexpr static long SPHERE=2;
  constexpr static long CYLINDER=3;
  constexpr static long LINE_STRIP=4;
  constexpr static long LINE_LIST=5;
  constexpr static long CUBE_LIST=6;
  constexpr static long SPHERE_LIST=7;
  constexpr static long POINTS=8;
  constexpr static long TEXT_VIEW_FACING=9;
  constexpr static long MESH_RESOURCE=10;
  constexpr static long TRIANGLE_LIST=11;
  constexpr static long ADD=0;
  constexpr static long MODIFY=0;
  constexpr static long DELETE=2;
  constexpr static long DELETEALL=3;

  Header header;
  std::string ns;
  long id;
  long type;
  long action;
  Pose pose;
  Vector3 scale;
  ColorRGBA color;
  Duration lifetime;
  bool frame_locked;

  std::vector<Point> points;
  std::vector<ColorRGBA> colors;

  std::string texture_resource;

};


template<>
struct rclcpp::TypeAdapter<
   Marker,
   visualization_msgs::msg::Marker
>
{
  using is_specialized = std::true_type;
  using custom_type = Marker;
  using ros_message_type = visualization_msgs::msg::Marker;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    destination.ns = source.ns;
    destination.id = source.id;
    destination.type = source.type;
    destination.action = source.action;
    PoseTypeAdapter::convert_to_ros_message(source.pose, destination.pose);
    Vector3TypeAdapter::convert_to_ros_message(source.scale, destination.scale);
    ColorRGBATypeAdapter::convert_to_ros_message(source.color, destination.color);
    DurationTypeAdapter::convert_to_ros_message(source.lifetime, destination.lifetime);
    destination.frame_locked = source.frame_locked;

    for (int i = 0; i < source.points.size(); i++)
    {
      PointTypeAdapter::convert_to_ros_message(source.points.at(i), destination.points[i]);
    }
    for (int i = 0; i < source.colors.size(); i++)
    {
      ColorRGBATypeAdapter::convert_to_ros_message(source.colors.at(i), destination.colors[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    destination.ns = source.ns;
    destination.id = source.id;
    destination.type = source.type;
    destination.action = source.action;
    PoseTypeAdapter::convert_to_custom(source.pose, destination.pose);
    Vector3TypeAdapter::convert_to_custom(source.scale, destination.scale);
    ColorRGBATypeAdapter::convert_to_custom(source.color, destination.color);
    DurationTypeAdapter::convert_to_custom(source.lifetime, destination.lifetime);
    destination.frame_locked = source.frame_locked;

    for (int i = 0; i < sizeof(source.points)/sizeof(*source.points); i++)
    {
      PointTypeAdapter::convert_to_custom(source.points[i], destination.points.at(i));
    }
    for (int i = 0; i < sizeof(source.colors)/sizeof(*source.colors); i++)
    {
      ColorRGBATypeAdapter::convert_to_custom(source.colors[i], destination.colors.at(i));
    }
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MARKERTYPEADAPTER_HPP_

#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__IMAGEMARKERTYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__IMAGEMARKERTYPEADAPTER_HPP_

#include <cinttypes>
#include <vector>
#include <string>

#include "visualization_msgs/msg/image_marker.hpp"

#include "rclcpp/type_adapter.hpp"

#include "std_msgs/msg/header.hpp"
#include "std_msgs/msg/color_rgba.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/ColorRGBATypeAdapter.hpp"

#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs_type_adaptations/include/PointTypeAdapter.hpp"

#include "builtin_interfaces/msg/duration.hpp"
#include "builtin_interfaces_type_adaptations/include/DurationTypeAdapter.hpp"

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;
using ColorRGBATypeAdapter = rclcpp::TypeAdapter<ColorRGBA, std_msgs::msg::ColorRGBA>;
using PointTypeAdapter = rclcpp::TypeAdapter<Point, geometry_msgs::msg::Point>;
using DurationTypeAdapter = rclcpp::TypeAdapter<Duration, builtin_interfaces::msg::Duration>;

struct ImageMarker
{
  constexpr static long CIRCLE = 0;
  constexpr static long LINE_STRIP = 1;
  constexpr static long LINE_LIST = 2;
  constexpr static long POLYGON = 3;
  constexpr static long POINTS = 4;

  constexpr static long ADD = 0;
  constexpr static long REMOVE = 1;

  Header header;
  std::string ns;
  long id;
  long type;
  long action;
  Point position;
  float scale;
  ColorRGBA outline_color;
  unsigned char filled;
  ColorRGBA fill_color;
  Duration lifetime;

  std::vector<Point> points;
  std::vector<ColorRGBA> outline_colors;
};


template<>
struct rclcpp::TypeAdapter<
   ImageMarker,
   visualization_msgs::msg::ImageMarker
>
{
  using is_specialized = std::true_type;
  using custom_type = ImageMarker;
  using ros_message_type = visualization_msgs::msg::ImageMarker;

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
    PointTypeAdapter::convert_to_ros_message(source.position, destination.position);
    destination.scale = source.scale;
    ColorRGBATypeAdapter::convert_to_ros_message(source.outline_color, destination.outline_color);
    destination.filled = source.filled;
    ColorRGBATypeAdapter::convert_to_ros_message(source.fill_color, destination.fill_color);
    DurationTypeAdapter::convert_to_ros_message(source.lifetime, destination.lifetime);

    for (int i = 0; i < source.points.size(); i++)
    {
      PointTypeAdapter::convert_to_ros_message(source.points.at(i), destination.points[i]);
    }
    for (int i = 0; i < source.outline_colors.size(); i++)
    {
      ColorRGBATypeAdapter::convert_to_ros_message(source.outline_colors.at(i), destination.outline_colors[i]);
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
    PointTypeAdapter::convert_to_custom(source.position, destination.position);
    destination.scale = source.scale;
    ColorRGBATypeAdapter::convert_to_custom(source.outline_color, destination.outline_color);
    destination.filled = source.filled;
    ColorRGBATypeAdapter::convert_to_custom(source.fill_color, destination.fill_color);
    DurationTypeAdapter::convert_to_custom(source.lifetime, destination.lifetime);

    for (int i = 0; i < source.points.size(); i++)
    {
      PointTypeAdapter::convert_to_custom(source.points[i], destination.points.at(i));
    }
    for (int i = 0; i < source.outline_colors.size(); i++)
    {
      ColorRGBATypeAdapter::convert_to_custom(source.outline_colors[i], destination.outline_colors.at(i));
    }
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__IMAGEMARKERTYPEADAPTER_HPP_

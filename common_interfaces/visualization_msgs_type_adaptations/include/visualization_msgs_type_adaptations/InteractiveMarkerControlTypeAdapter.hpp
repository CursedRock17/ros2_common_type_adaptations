#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERCONTROLTYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERCONTROLTYPEADAPTER_HPP_

#include <cinttypes>
#include <vector>
#include <string>

#include "visualization_msgs/msg/interactive_marker_control.hpp"
#include "rclcpp/type_adapter.hpp"

#include "visualization_msgs/msg/marker.hpp"
#include "MarkerTypeAdapter.hpp"

#include "geometry_msgs/msg/quaternion.hpp"
#include "geometry_msgs_type_adaptations/include/QuaternionTypeAdapter.hpp"

using QuaternionTypeAdapter = rclcpp::TypeAdapter<Quaternion, geometry_msgs::msg::Quaternion>;
using MarkerTypeAdapter = rclcpp::TypeAdapter<Marker, visualization_msgs::msg::Marker>;

struct InteractiveMarkerControl
{
  std::string name;
  Quaternion orientation;

  constexpr static unsigned char INHERIT = 0;
  constexpr static unsigned char FIXED = 1;
  constexpr static unsigned char VIEW_FACING = 2;

  unsigned char orientation_mode;

  constexpr static unsigned char NONE = 0;
  constexpr static unsigned char MENU = 1;
  constexpr static unsigned char BUTTON = 2;
  constexpr static unsigned char MOVE_AXIS = 3;
  constexpr static unsigned char MOVE_PLANE = 4;
  constexpr static unsigned char ROTATE_AXIS = 5;
  constexpr static unsigned char MOVE_ROTATE = 6;
  constexpr static unsigned char MOVE_3D = 7;
  constexpr static unsigned char ROTATE_3D = 8;
  constexpr static unsigned char MOVE_ROTATE_3D = 9;

  unsigned char interaction_mode;
  bool always_visible;

  std::vector<Marker> markers;

  bool independent_marker_orientation;
  std::string description;
};


template<>
struct rclcpp::TypeAdapter<
   InteractiveMarkerControl,
   visualization_msgs::msg::InteractiveMarkerControl
>
{
  using is_specialized = std::true_type;
  using custom_type = InteractiveMarkerControl;
  using ros_message_type = visualization_msgs::msg::InteractiveMarkerControl;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.name = source.name;
    QuaternionTypeAdapter::convert_to_ros_message(source.orientation, destination.orientation);

    destination.orientation_mode = source.orientation_mode;
    destination.interaction_mode = source.interaction_mode;
    destination.always_visible = source.always_visible

    for (int i = 0; i < source.markers.size(); i++)
    {
      MarkerTypeAdapter::convert_to_ros_message(source.markers.at(i), destination.markers[i]);
    }

    destination.independent_marker_orientation = source.independent_marker_orientation;
    destinatoin.description = source.description;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.name = source.name;
    QuaternionTypeAdapter::convert_to_custom(source.orientation, destination.orientation);

    destination.orientation_mode = source.orientation_mode;
    destination.interaction_mode = source.interaction_mode;
    destination.always_visible = source.always_visible

    for (int i = 0; i < sizeof(source.markers)/sizeof(*source.markers); i++)
    {
      MarkerTypeAdapter::convert_to_custom(source.markers[i], destination.markers.at(i));
    }

    destination.independent_marker_orientation = source.independent_marker_orientation;
    destination.description = source.description;
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERCONTROLTYPEADAPTER_HPP_

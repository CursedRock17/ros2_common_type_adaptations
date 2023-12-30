#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERFEEDBACKTYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERFEEDBACKTYPEADAPTER_HPP_

#include <string>

#include "visualization_msgs/msg/interactive_marker_feedback.hpp"
#include "rclcpp/type_adapter.hpp"

#include "std_msgs/msg/header.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs_type_adaptations/include/PoseTypeAdapter.hpp"
#include "geometry_msgs_type_adaptations/include/PoeTypeAdapter.hpp"

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;
using PoseTypeAdapter = rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>;
using PointTypeAdapter = rclcpp::TypeAdapter<Point, geometry_msgs::msg::Point>;

struct InteractiveMarkerPose
{
  Header header;
  std::string client_id;

  std::string marker_name;
  std::string control_name;

  constexpr static unsigned char KEEP_ALIVE = 0;
  constexpr static unsigned char POSE_UPDATE = 1;
  constexpr static unsigned char MENU_SELECT = 2;
  constexpr static unsigned char BUTTON_CLICK = 3;

  constexpr static unsigned char MOUSE_DOWN = 4;
  constexpr static unsigned char MOUSE_UP = 5;

  unsigned char event_type;

  Pose pose;
  unsigned long menu_entry_id;

  Point mouse_point;
  bool mouse_point_valid;
};


template<>
struct rclcpp::TypeAdapter<
   InteractiveMarkerPose,
   visualization_msgs::msg::InteractiveMarkerPose
>
{
  using is_specialized = std::true_type;
  using custom_type = InteractiveMarkerPose;
  using ros_message_type = visualization_msgs::msg::InteractiveMarkerPose;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    destination.client_id = source.client_id;

    destination.marker_name = source.marker_name;
    destination.control_name = source.control_name;
    destination.event_type = source.event_type;

    PoseTypeAdapter::convert_to_ros_message(source.pose, destination.pose);
    destination.menu_entry_id = source.menu_entry_id;

    PointTypeAdapter::convert_to_ros_message(source.mouse_point, destination.mouse_point);
    destination.mouse_point_valid = source.mouse_point_valid;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    destination.client_id = source.client_id;

    destination.marker_name = source.marker_name;
    destination.control_name = source.control_name;
    destination.event_type = source.event_type;

    PoseTypeAdapter::convert_to_custom(source.pose, destination.pose);
    destination.menu_entry_id = source.menu_entry_id;

    PointTypeAdapter::convert_to_custom(source.mouse_point, destination.mouse_point);
    destination.mouse_point_valid = source.mouse_point_valid;
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERFEEDBACKTYPEADAPTER_HPP_

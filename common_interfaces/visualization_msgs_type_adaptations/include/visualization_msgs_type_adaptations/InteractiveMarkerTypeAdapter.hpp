#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERTYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERTYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "visualization_msgs/msg/interactive_marker.hpp"

#include "visualization_msgs/msg/menu_entry.hpp"
#include "visualization_msgs/msg/interactive_marker_control.hpp"
#include "MenuEntryTypeAdapter.hpp"
#include "InteractiveMarkerControlTypeAdapter.hpp"

#include "rclcpp/type_adapter.hpp"

#include "std_msgs/msg/header.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;
using PoseTypeAdapter = rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>;

using MenuEntryTypeAdapter = rclcpp::TypeAdapter<MenuEntry, visualization_msgs::msg::MenuEntry>;
using InteractiveMarkerControl = rclcpp::TypeAdapter<InteractiveMarkerControl, visualization_msgs::msg::InteractiveMarkerControl>;


struct InteractiveMarker
{
  Header header;
  Pose pose;

  std::string name;
  std::string description;

  float scale;

  std::vector<MenuEntry> menu_entries;
  std::vector<InteractiveMarkerControl> controls;
};


template<>
struct rclcpp::TypeAdapter<
   InteractiveMarker,
   visualization_msgs::msg::InteractiveMarker
>
{
  using is_specialized = std::true_type;
  using custom_type = InteractiveMarker;
  using ros_message_type = visualization_msgs::msg::InteractiveMarker;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    PoseTypeAdapter::convert_to_ros_message(source.pose, destination.pose);

    destination.name = source.name;
    destination.description = source.description;
    destination.scale = source.scale;

    for (int i = 0; i < source.menu_entries.size(); i++)
    {
      MenuEntryTypeAdapter::convert_to_ros_message(source.menu_entries.at(i), destination.menu_entries[i]);
    }
    for (int i = 0; i < source.controls.size(); i++)
    {
      InteractiveMarkerControlTypeAdapter::convert_to_ros_message(source.controls.at(i), destination.controls[i]);
    }


  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    PoseTypeAdapter::convert_to_custom(source.pose, destination.pose);

    destination.name = source.name;
    destination.description = source.description;
    destination.scale = source.scale;


    for (int i = 0; i < sizeof(source.menu_entries)/sizeof(*source.menu_entries); i++)
    {
      MenuEntryTypeAdapter::convert_to_custom(source.menu_entries[i], destination.menu_entries.at(i));
    }

    for (int i = 0; i < sizeof(source.controls)/sizeof(*source.controls); i++)
    {
      InteractiveMarkerControlTypeAdapter::convert_to_custom(source.controls[i], destination.controls.at(i));
    }

  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERTYPEADAPTER_HPP_

#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MENUENTRYTYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MENUENTRYTYPEADAPTER_HPP_

#include <cinttypes>
#include <vector>
#include <string>

#include "visualization_msgs/msg/menu_entry.hpp"
#include "rclcpp/type_adapter.hpp"

struct MenuEntry
{
  unsigned long id;
  unsigned long parent_id;

  std::string title;
  std::string command;

  constexpr static unsigned char FEEDBACK = 0;
  constexpr static unsigned char ROSRUN = 1;
  constexpr static unsigned char ROSLAUNCH = 2;

  unsigned char command_type;
};


template<>
struct rclcpp::TypeAdapter<
   MenuEntry,
   visualization_msgs::msg::MenuEntry
>
{
  using is_specialized = std::true_type;
  using custom_type = MenuEntry;
  using ros_message_type = visualization_msgs::msg::MenuEntry;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.id = source.id;
    destination.parent_id = source.parent_id;
    destination.title = source.title;
    destination.command = source.command;
    destination.command_type = source.command_type;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.id = source.id;
    destination.parent_id = source.parent_id;
    destination.title = source.title;
    destination.command = source.command;
    destination.command_type = source.command_type;
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MENUENTRYTYPEADAPTER_HPP_

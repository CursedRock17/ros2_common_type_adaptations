#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERINITTYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERINITTYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "visualization_msgs/msg/interactive_marker_init.hpp"
#include "rclcpp/type_adapter.hpp"

#include "visualization_msgs/msg/interactive_marker.hpp"
#include "InteractiveMarkerTypeAdapter.hpp"

using InteractiveMarkerTypeAdapter = rclcpp::TypeAdapter<InteractiveMarker, visualization_msgs::msg::InteractiveMarker>;

struct InteractiveMarkerInit
{
  std::string server_id;
  unsigned long long seq_num;
  std::vector<InteractiveMarker> markers;
};


template<>
struct rclcpp::TypeAdapter<
   InteractiveMarkerInit,
   visualization_msgs::msg::InteractiveMarkerInit
>
{
  using is_specialized = std::true_type;
  using custom_type = InteractiveMarkerInit;
  using ros_message_type = visualization_msgs::msg::InteractiveMarkerInit;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.server_id = source.server_id;
    destination.seq_num = source.seq_num;
    for (int i = 0; i < source.markers.size(); i++)
    {
      InteractiveMarkerTypeAdapter::convert_to_ros_message(source.markers.at(i), destination.markers[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.server_id = source.server_id;
    destination.seq_num = source.seq_num;
    for (int i = 0; i < source.markers.size(); i++)
    {
      InteractiveMarkerTypeAdapter::convert_to_custom(source.markers[i], destination.markers.at(i));
    }
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERINITTYPEADAPTER_HPP_

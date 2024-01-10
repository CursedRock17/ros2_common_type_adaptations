#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERUPDATETYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERUPDATETYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "visualization_msgs/msg/interactive_marker_update.hpp"
#include "rclcpp/type_adapter.hpp"

#include "visualization_msgs/msg/interactive_marker.hpp"
#include "visualization_msgs/msg/interactive_marker_pose.hpp"
#include "InteractiveMarkerTypeAdapter.hpp"
#include "InteractiveMarkerPoseTypeAdapter.hpp"

using InteractiveMarkerTypeAdapter = rclcpp::TypeAdapter
  <InteractiveMarker, visualization_msgs::msg::InteractiveMarker>;
using InteractiveMarkerPoseTypeAdapter = rclcpp::TypeAdapter
  <InteractiveMarkerPose, visualization_msgs::msg::InteractiveMarkerPose>;

struct InteractiveMarkerUpdate
{
  std::stirng server_id;
  unsigned long long seq_num;

  constexpr static unsigned char KEEP_ALIVE = 0;
  constexpr static unsigned char UPDATE = 1;

  unsigned char type;

  std::vector<InteractiveMarker> markers;
  std::vector<InteractiveMarkerPose> poses;
  std::vector<std::string> erases;
};


template<>
struct rclcpp::TypeAdapter<
   InteractiveMarkerUpdate,
   visualization_msgs::msg::InteractiveMarkerUpdate
>
{
  using is_specialized = std::true_type;
  using custom_type = InteractiveMarkerUpdate;
  using ros_message_type = visualization_msgs::msg::InteractiveMarkerUpdate;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.server_id = source.server_id;
    destination.seq_num = source.seq_num;
    destination.type = source.type;

    for (int i = 0; i < source.markers.size(); i++)
    {
      InteractiveMarkerTypeAdapter::convert_to_ros_message(source.markers.at(i), destination.markers[i]);
    }

    for (int i = 0; i < source.poses.size(); i++)
    {
      InteractiveMarkerPoseTypeAdapter::convert_to_ros_message(
        source.poses.at(i), destination.poses[i]);
    }

    for (int i = 0; i < source.erases.size(); i++)
    {
      destination.erases[i] = source.erases.at(i);
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
    destination.type = source.type;

    for (int i = 0; i < source.markers.size(); i++)
    {
      InteractiveMarkerTypeAdapter::convert_to_custom(source.markers[i], destination.markers.at(i));
    }

    for (int i = 0; i < source.poses.size(); i++)
    {
      InteractiveMarkerPoseTypeAdapter::convert_to_custom(source.poses[i], destination.poses.at(i));
    }

    for (int i = 0; i < source.erases.size(); i++)
    {
      destination.erases.at(i) = destination.erases[i];
    }
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__INTERACTIVEMARKERUPDATETYPEADAPTER_HPP_

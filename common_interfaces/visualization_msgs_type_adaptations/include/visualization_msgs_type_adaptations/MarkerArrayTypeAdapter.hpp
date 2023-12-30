#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MARKERARRAYTYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MARKERARRAYTYPEADAPTER_HPP_

#include "visualization_msgs/msg/marker_array.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "rclcpp/type_adapter.hpp"

#include "MarkerTypeAdapter.hpp"

using MarkerTypeAdapter = rclcpp::TypeAdapter<Marker, visualization_msgs::msg::Marker>;

struct MarkerArray
{
  std::vector<Marker> markers;
};


template<>
struct rclcpp::TypeAdapter<
   MarkerArray,
   visualization_msgs::msg::MarkerArray
>
{
  using is_specialized = std::true_type;
  using custom_type = MarkerArray;
  using ros_message_type = visualization_msgs::msg::MarkerArray;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    for (int i = 0; i < source.markers.size(); i++)
    {
      MarkerTypeAdapter::convert_to_ros_message(source.markers.at(i), destination.markers[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    for (int i = 0; i < sizeof(source.markers)/sizeof(*source.markers); i++)
    {
      MarkerTypeAdapter::convert_to_custom(source.markers[i], destination.markers.at(i));
    }
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MARKERARRAYTYPEADAPTER_HPP_

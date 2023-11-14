#ifndef NAV_MSGS_TYPE_ADAPTATIONS__MAPMETADATATYPEADAPTER_HPP_
#define NAV_MSGS_TYPE_ADAPTATIONS__MAPMETADATATYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "nav_msgs/msg/map_meta_data.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "builtin_interfaces/msg/time.hpp"

#include "builtin_interfaces_type_adaptations/include/TimeTypeAdapter.hpp"
#include "geometry_msgs_type_adaptations/include/PoseTypeAdapter.hpp"

struct MapMetaData
{
  Time map_load_time;
  float resolution;
  unsigned long width;
  unsigned long height;
  Pose origin;
};

using TimeTypeAdapter = rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>;
using PoseTypeAdapter = rclcpp::TypeAdapter<Pose, geometry_msgs::msg::Pose>;

template<>
struct rclcpp::TypeAdapter<
   MapMetaData,
   nav_msgs::msg::MapMetaData
>
{
  using is_specialized = nav::true_type;
  using custom_type = MapMetaData;
  using ros_message_type = nav_msgs::msg::MapMetaData;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    TimeTypeAdapter::convert_to_ros_message(source.map_load_time, destination.map_load_time);
    destination.resolution = source.resolution;
    destination.width = source.width;
    destination.height = source.height;
    PoseTypeAdapter::convert_to_ros_message(source.origin, destination.origin);
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    TimeTypeAdapter::convert_to_custom(source.map_load_time, destination.map_load_time);
    destination.resolution = source.resolution;
    destination.width = source.width;
    destination.height = source.height;
    PoseTypeAdapter::convert_to_custom(source.origin, destination.origin);
  }
};

#endif  // NAV_MSGS_TYPE_ADAPTATIONS__MAPMETADATATYPEADAPTER_HPP_

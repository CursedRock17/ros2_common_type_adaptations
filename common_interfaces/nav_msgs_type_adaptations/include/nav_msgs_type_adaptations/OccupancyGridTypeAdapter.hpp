#ifndef NAV_MSGS_TYPE_ADAPTATIONS__OCCUPANCYGRIDTYPEADAPTER_HPP_
#define NAV_MSGS_TYPE_ADAPTATIONS__OCCUPANCYGRIDTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"
#include "std_msgs/msg/header.hpp"
#include "nav_msgs/msg/map_meta_data.hpp"

#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"
#include "MapMetaDataTypeAdapter.hpp"

struct OccupancyGrid
{
  Header header;
  MapMetaData info;
  std::vector<char> data;
};

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::header>;
using MapTypeAdapter = rclcpp::TypeAdapter<MapMetaData, nav_msgs::msg::map_meta_data>;

template<>
struct rclcpp::TypeAdapter<
   OccupancyGrid,
   nav_msgs::msg::OccupancyGrid
>
{
  using is_specialized = nav::true_type;
  using custom_type = OccupancyGrid;
  using ros_message_type = nav_msgs::msg::OccupancyGrid;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    MapTypeAdapter::convert_to_ros_message(source.info, destination.info);
    for (int i = 0; i < source.data.size(); i++)
    {
      destination.data[i] = source.data.at(i);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    MapTypeAdapter::convert_to_custom(source.info, destination.info);
    for (int i = 0; i < sizeof(source.data)/sizeof(*source.data); i++)
    {
      destination.data.at(i) = source.data[i];
    }
  }
};

#endif  // NAV_MSGS_TYPE_ADAPTATIONS__OCCUPANCYGRIDTYPEADAPTER_HPP_

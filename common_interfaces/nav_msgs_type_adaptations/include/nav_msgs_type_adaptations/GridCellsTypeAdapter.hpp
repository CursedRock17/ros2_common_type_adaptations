#ifndef NAV_MSGS_TYPE_ADAPTATIONS__GRIDCELLSTYPEADAPTER_HPP_
#define NAV_MSGS_TYPE_ADAPTATIONS__GRIDCELLSTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "nav_msgs/msg/grid_cells.hpp"
#include "std_msgs/msg/header.hpp"
#include "geometry_msgs/msg/point.hpp"

#include "geometry_msgs_type_adaptations/include/PointTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct GridCells
{
  Header header;
  float cell_width;
  float cell_height;
  std::vector<Point> cells;
};

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::header>;
using PointTypeAdapter = rclcpp::TypeAdapter<Point, geometry_msgs::msg::Point>;

template<>
struct rclcpp::TypeAdapter<
   GridCells,
   nav_msgs::msg::GridCells
>
{
  using is_specialized = nav::true_type;
  using custom_type = GridCells;
  using ros_message_type = nav_msgs::msg::GridCells;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    destination.cell_width = source.cell_width;
    destination.cell_height = source.cell_height;
    for (int i = 0; i < source.cells.size(); i++)
    {
      PointTypeAdapter::convert_to_ros_message(source.cells.at(i), destination.cells[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    destination.cell_width = source.cell_width;
    destination.cell_height = source.cell_height;
    for (int i = 0; i < sizeof(source.cells)/sizeof(*source.cells); i++)
    {
      PointTypeAdapter::convert_to_custom(source.cells[i], destination.cells.at(i));
    }
  }
};

#endif  // NAV_MSGS_TYPE_ADAPTATIONS__GRIDCELLSTYPEADAPTER_HPP_

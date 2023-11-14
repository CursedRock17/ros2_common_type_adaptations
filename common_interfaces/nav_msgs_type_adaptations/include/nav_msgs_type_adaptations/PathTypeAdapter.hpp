#ifndef NAV_MSGS_TYPE_ADAPTATIONS__PATHTYPEADAPTER_HPP_
#define NAV_MSGS_TYPE_ADAPTATIONS__PATHTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "nav_msgs/msg/path.hpp"
#include "std_msgs/msg/header.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "geometry_msgs_type_adaptations/include/PoseStampedTypeAdapter.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

struct Path
{
  Header header;
  std::vector<PoseStamped> poses;
};

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::header>;
using PoseStampedTypeAdapter = rclcpp::TypeAdapter<PoseStamped, geometry_msgs::msg::PoseStamped>;

template<>
struct rclcpp::TypeAdapter<
   Path,
   nav_msgs::msg::Path
>
{
  using is_specialized = nav::true_type;
  using custom_type = Path;
  using ros_message_type = nav_msgs::msg::Path;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    for (int i = 0; i < source.poses.size(); i++)
    {
      PoseStampedTypeAdapter::convert_to_ros_message(source.poses.at(i), destination.poses[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    for (int i = 0; i < sizeof(source.poses)/sizeof(*source.poses); i++)
    {
      PoseStampedTypeAdapter::convert_to_custom(source.poses[i], destination.poses.at(i));
    }
  }
};

#endif  // NAV_MSGS_TYPE_ADAPTATIONS__PATHTYPEADAPTER_HPP_

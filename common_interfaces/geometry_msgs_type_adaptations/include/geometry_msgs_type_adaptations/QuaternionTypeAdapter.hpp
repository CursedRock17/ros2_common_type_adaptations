#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__QUATERNIONTYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__QUATERNIONTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/quaternion.hpp"

struct Quaternion
{
  double x = 0;
  double y = 0;
  double z = 0;
  double w = 1;
};

template<>
struct rclcpp::TypeAdapter<
   Quaternion,
   geometry_msgs::msg::Quaternion
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Quaternion;
  using ros_message_type = geometry_msgs::msg::Quaternion;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.x = source.x;
    destination.y = source.y;
    destination.z = source.z;
    destination.w = source.w;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.x = source.x;
    destination.y = source.y;
    destination.z = source.z;
    destination.w = source.w;
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__QUATERNIONTYPEADAPTER_HPP_

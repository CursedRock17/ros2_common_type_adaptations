#ifndef GEOMETRY_MSGS_TYPE_ADAPTATIONS__INERTIATYPEADAPTER_HPP_
#define GEOMETRY_MSGS_TYPE_ADAPTATIONS__INERTIATYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "geometry_msgs/msg/inertia.hpp"
#include "geometry_msgs/msg/vector3.hpp"

#include "Vector3TypeAdapter.hpp"

struct Inertia
{
  double m;
  Vector3 com;

  double ixx;
  double ixy;
  double ixz;
  double iyy;
  double iyz;
  double izz;
};

template<>
struct rclcpp::TypeAdapter<
   Inertia,
   geometry_msgs::msg::Inertia
>
{
  using is_specialized = geometry::true_type;
  using custom_type = Inertia;
  using ros_message_type = geometry_msgs::msg::Inertia;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_ros_message(
      source.com, destination.com);

    destination.m = source.m;
    destination.ixx = source.ixx;
    destination.ixy = source.ixy;
    destination.ixz = source.ixz;
    destination.iyy = source.iyy;
    destination.iyz = source.iyz;
    destination.izz = source.izz;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<Vector3, geometry_msgs::msg::Vector3>::convert_to_custom(
      source.com, destination.com);

    destination.m = source.m;
    destination.ixx = source.ixx;
    destination.ixy = source.ixy;
    destination.ixz = source.ixz;
    destination.iyy = source.iyy;
    destination.iyz = source.iyz;
    destination.izz = source.izz;
  }
};

#endif  // GEOMETRY_MSGS_TYPE_ADAPTATIONS__INERTIATYPEADAPTER_HPP_

#ifndef STD_MSGS_TYPE_ADAPTATIONS__MULTIARRAYDIMENSIONTYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__MULTIARRAYDIMENSIONTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/multi_array_dimension.hpp"

struct MultiArrayDimension
{
  std::string label;
  unsigned long size;
  unsigned long stride;
};

template<>
struct rclcpp::TypeAdapter<
   MultiArrayDimension,
   std_msgs::msg::MultiArrayDimension
>
{
  using is_specialized = std::true_type;
  using custom_type = MultiArrayDimension;
  using ros_message_type = std_msgs::msg::MultiArrayDimension;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.label = source.label;
    destination.size = source.size;
    destination.stride = source.stride;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.label = source.label;
    destination.size = source.size;
    destination.stride = source.stride;
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__MULTIARRAYDIMENSIONTYPEADAPTER_HPP_

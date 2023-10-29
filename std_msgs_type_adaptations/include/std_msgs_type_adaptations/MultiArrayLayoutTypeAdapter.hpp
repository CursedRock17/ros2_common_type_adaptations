#ifndef STD_MSGS_TYPE_ADAPTATIONS__MULTIARRAYLAYOUTTYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__MULTIARRAYLAYOUTTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/multi_array_layout.hpp"
#include "std_msgs/msg/multi_array_dimension.hpp"

#include "MultiArrayDimensionTypeAdapter.hpp"

using MultiArrayDimensionAdapter =
  rclcpp::TypeAdapter<MultiArrayDimension, std_msgs::msg::MultiArrayDimension>

struct MultiArrayLayout
{
  MultiArrayDimension dim;
  unsigned long data_offset;
};

template<>
struct rclcpp::TypeAdapter<
   MultiArrayLayout,
   std_msgs::msg::MultiArrayLayout
>
{
  using is_specialized = std::true_type;
  using custom_type = MultiArrayLayout;
  using ros_message_type = std_msgs::msg::MultiArrayLayout;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    MultiArrayDimensionAdapter::convert_to_ros_message(source.dim, destination.dim);

    destination.dim = source.dim;
    destination.data_offset = source.data_offset;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    MultiArrayDimensionAdapter::convert_to_custom_message(source.dim, destination.dim);

    destination.dim = source.dim;
    destination.data_offset = source.data_offset;
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__MULTIARRAYLAYOUTTYPEADAPTER_HPP_

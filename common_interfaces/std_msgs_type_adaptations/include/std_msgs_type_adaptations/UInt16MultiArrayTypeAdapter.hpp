#ifndef STD_MSGS_TYPE_ADAPTATIONS__UINT16MULTIARRAYTYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__UINT16MULTIARRAYTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/multi_array_layout.hpp"
#include "std_msgs/msg/u_int16_multi_array.hpp"

#include "MultiArrayLayoutTypeAdapter.hpp"

using MultiArrayLayoutAdapter =
  rclcpp::TypeAdapter<MultiArrayLayout, std_msgs::msg::MultiArrayLayout>

struct UInt16MultiArray
{
  MultiArrayLayout layout;
  std::vector<unsigned short> data;
};

template<>
struct rclcpp::TypeAdapter<
   UInt16MultiArray,
   std_msgs::msg::UInt16MultiArray
>
{
  using is_specialized = std::true_type;
  using custom_type = UInt16MultiArray;
  using ros_message_type = std_msgs::msg::UInt16MultiArray

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    MultiArrayLayoutAdapter::convert_to_ros_message(source.layout, destination.layout);

    destination.layout = source.layout;
    for(int i = 0; i < sizeof(destination.data)/sizeof(*destination.data); i++)
    {
      destination.data[i] = source.data[i];
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    MultiArrayLayoutAdapter::convert_to_custom_message(source.layout, destination.layout);

    destination.layout = source.layout;
    for(int i = 0; i < sizeof(source.data)/sizeof(*source.data); i++)
    {
      destination.data[i] = source.data[i];
    }
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__UINT16MULTIARRAYTYPEADAPTER_HPP_

#ifndef STD_MSGS_TYPE_ADAPTATIONS__INT8MULTIARRAYTYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__INT8MULTIARRAYTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/multi_array_layout.hpp"
#include "std_msgs/msg/int8_multi_array.hpp"

#include "MultiArrayLayoutTypeAdapter.hpp"

using MultiArrayLayoutAdapter =
  rclcpp::TypeAdapter<MultiArrayLayout, std_msgs::msg::MultiArrayLayout>

struct Int8MultiArray
{
  MultiArrayLayout layout;
  std::vector<char> data;
};

template<>
struct rclcpp::TypeAdapter<
   Int8MultiArray,
   std_msgs::msg::Int8MultiArray
>
{
  using is_specialized = std::true_type;
  using custom_type = Int8MultiArray;
  using ros_message_type = std_msgs::msg::Int8MultiArray

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

#endif  // STD_MSGS_TYPE_ADAPTATIONS__INT8MULTIARRAYTYPEADAPTER_HPP_

#ifndef STD_MSGS_TYPE_ADAPTATIONS__INT64MULTIARRAYTYPEADAPTER_HPP_
#define STD_MSGS_TYPE_ADAPTATIONS__INT64MULTIARRAYTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "std_msgs/msg/multi_array_layout.hpp"
#include "std_msgs/msg/int64_multi_array.hpp"

#include "MultiArrayLayoutTypeAdapter.hpp"

using MultiArrayLayoutAdapter =
  rclcpp::TypeAdapter<MultiArrayLayout, std_msgs::msg::MultiArrayLayout>

struct Int64MultiArray
{
  MultiArrayLayout layout;
  std::vector<long long> data;
};

template<>
struct rclcpp::TypeAdapter<
   Int64MultiArray,
   std_msgs::msg::Int64MultiArray
>
{
  using is_specialized = std::true_type;
  using custom_type = Int64MultiArray;
  using ros_message_type = std_msgs::msg::Int64MultiArray

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    MultiArrayLayoutAdapter::convert_to_ros_message(source.layout, destination.layout);

    destination.layout = source.layout;
    for(int i = 0; i < source.data.size(); i++)
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
    for(int i = 0; i < source.data.size(); i++)
    {
      destination.data[i] = source.data[i];
    }
  }
};

#endif  // STD_MSGS_TYPE_ADAPTATIONS__INT64MULTIARRAYTYPEADAPTER_HPP_

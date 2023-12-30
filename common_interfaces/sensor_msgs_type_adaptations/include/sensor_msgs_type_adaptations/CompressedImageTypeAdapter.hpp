#ifndef SENSOR_MSGS_TYPE_ADAPTATIONS__COMPRESSEDIMAGETYPEADAPTER_HPP_
#define SENSOR_MSGS_TYPE_ADAPTATIONS__COMPRESSEDIMAGETYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "sensor_msgs/msg/compressed_image.hpp"
#include "rclcpp/type_adapter.hpp"

#include "std_msgs/msg/header.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;

struct CompressedImage
{
  Header header;
  std::string format;
  std::vector<unsigned char> data;
};


template<>
struct rclcpp::TypeAdapter<
   CompressedImage,
   sensor_msgs::msg::CompressedImage
>
{
  using is_specialized = std::true_type;
  using custom_type = CompressedImage;
  using ros_message_type = sensor_msgs::msg::CompressedImage;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    destination.format = source.format;
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
    destination.format = source.format;
    for (int i = 0; i < sizeof(source.data)/sizeof(*source.data); i++)
    {
      destination.data.at(i) = source.data[i];
    }
  }
};

#endif  // SENSOR_MSGS_TYPE_ADAPTATIONS__COMPRESSEDIMAGETYPEADAPTER_HPP_

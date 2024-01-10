#ifndef VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MESHFILETYPEADAPTER_HPP_
#define VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MESHFILETYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "visualization_msgs/msg/mesh_file.hpp"
#include "rclcpp/type_adapter.hpp"

struct MeshFile
{
  std::string filename;
  std::vector<unsigned char> data;
};


template<>
struct rclcpp::TypeAdapter<
   MeshFile,
   visualization_msgs::msg::MeshFile
>
{
  using is_specialized = std::true_type;
  using custom_type = MeshFile;
  using ros_message_type = visualization_msgs::msg::MeshFile;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.filename = source.filename;
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
    destination.filename = source.filename;
    for (int i = 0; i < source.data.size(); i++)
    {
      destination.data.at(i) = source.data[i];
    }
  }
};

#endif  // VISUALIZATION_MSGS_TYPE_ADAPTATIONS__MESHFILETYPEADAPTER_HPP_

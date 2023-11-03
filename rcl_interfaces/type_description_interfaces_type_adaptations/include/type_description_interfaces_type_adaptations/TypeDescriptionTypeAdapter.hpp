#ifndef TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__TYPEDESCRIPTIONTYPEADAPTER_HPP_
#define TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__TYPEDESCRIPTIONTYPEADAPTER_HPP_

#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "type_description_interfaces/msg/individual_type_description.hpp"
#include "type_description_interfaces/msg/type_description.hpp"

#include "IndividualTypeDescriptionTypeAdapter.hpp"

struct TypeDescription
{
  IndividualTypeDescription type_description;
  std::vector<IndividualTypeDescription> referenced_type_descriptions;
};


template<>
struct rclcpp::TypeAdapter<
  TypeDescription,
  type_description_interfaces::msg::TypeDescription
>
{
  using is_specialized = std::true_type;
  using custom_type = TypeDescription;
  using ros_message_type = type_description_interfaces::msg::TypeDescription;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
      rclcpp::TypeAdapter<IndividualTypeDescription, type_description_interfaces::msg::IndividualTypeDescription>::convert_to_ros_message(source.type_description, destination.type_description);
    for(int i = 0; i < source.referenced_type_descriptions.size(); i++)
    {
      rclcpp::TypeAdapter<Field, type_description_interfaces::msg::Field>::convert_to_ros_message(
        source.referenced_type_descriptions.at(i), destination.referenced_type_descriptions[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    rclcpp::TypeAdapter<IndividualTypeDescription, type_description_interfaces::msg::IndividualTypeDescription>::convert_to_custom(source.type_description, destination.type_description);
    for(int i = 0; i < destination.referenced_type_descriptions.size(); i++)
    {
      rclcpp::TypeAdapter<Field, type_description_interfaces::msg::Field>::convert_to_custom(
        source.referenced_type_descriptions[i], destination.referenced_type_descriptions.at(i));
    }
  }
};

#endif  // TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__TYPEDESCRIPTIONTYPEADAPTER_HPP_

#ifndef TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__INDIVIDUALTYPEDESCRIPTIONTYPEADAPTER_HPP_
#define TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__INDIVIDUALTYPEDESCRIPTIONTYPEADAPTER_HPP_

#include <string>
#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "type_description_interfaces/msg/field.hpp"
#include "type_description_interfaces/msg/individual_type_description.hpp"

#include "FieldTypeAdapter.hpp"

struct IndividualTypeDescription
{
  std::string type_name;
  std::vector<Field> field;
};


template<>
struct rclcpp::TypeAdapter<
  IndividualTypeDescription,
  type_description_interfaces::msg::IndividualTypeDescription
>
{
  using is_specialized = std::true_type;
  using custom_type = IndividualTypeDescription;
  using ros_message_type = type_description_interfaces::msg::IndividualTypeDescription;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.type_name = source.type_name;
    for(int i = 0; i < source.field.size(); i++)
    {
      rclcpp::TypeAdapter<Field, type_description_interfaces::msg::Field>::convert_to_ros_message(source.field.at(i), destination.field[0]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.type_name = source.type_name;
    for(int i = 0; i < destination.field.size(); i++)
    {
      rclcpp::TypeAdapter<Field, type_description_interfaces::msg::Field>::convert_to_custom(source.field[i], destination.field.at(i));
    }
  }
};

#endif  // TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__INDIVIDUALTYPEDESCRIPTIONTYPEADAPTER_HPP_

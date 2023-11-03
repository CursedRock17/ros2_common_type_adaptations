#ifndef TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__FIELDTYPETYPEADAPTER_HPP_
#define TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__FIELDTYPETYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "type_description_interfaces/msg/field.hpp"
#include "type_description_interfaces/msg/field_type.hpp"

#include "FieldTypeTypeAdapter.hpp"

struct Field
{
  std::string name;
  FieldType type;
  std::string default_value;
};


template<>
struct rclcpp::TypeAdapter<
  Field,
  type_description_interfaces::msg::Field
>
{
  using is_specialized = std::true_type;
  using custom_type = Field;
  using ros_message_type = type_description_interfaces::msg::Field;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.name = source.name;
    rclcpp::TypeAdapter<FieldType, type_description_interfaces::msg::FieldType>::convert_to_ros_message(source.type, destination.type);
    destination.default_value = source.default_value;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.name = source.name;
    rclcpp::TypeAdapter<FieldType, type_description_interfaces::msg::FieldType>::convert_to_custom(source.type, destination.type);
    destination.default_value = source.default_value;
  }
};

#endif  // TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__FIELDTYPETYPEADAPTER_HPP_

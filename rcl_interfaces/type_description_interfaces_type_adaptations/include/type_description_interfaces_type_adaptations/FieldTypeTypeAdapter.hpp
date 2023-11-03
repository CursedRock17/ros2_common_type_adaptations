#ifndef TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__FIELDTYPETYPEADAPTER_HPP_
#define TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__FIELDTYPETYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "type_description_interfaces/msg/field_type.hpp"

struct FieldType
{
  static constexpr unsigned char FIELD_TYPE_NOT_SET = 0;
  static constexpr unsigned char FIELD_TYPE_NESTED_TYPE = 1;
  static constexpr unsigned char FIELD_TYPE_INT8 = 2;
  static constexpr unsigned char FIELD_TYPE_UINT8 = 3;
  static constexpr unsigned char FIELD_TYPE_INT16 = 4;
  static constexpr unsigned char FIELD_TYPE_UINT16 = 5;
  static constexpr unsigned char FIELD_TYPE_INT32 = 6;
  static constexpr unsigned char FIELD_TYPE_UINT32 = 7;
  static constexpr unsigned char FIELD_TYPE_INT64 = 8;
  static constexpr unsigned char FIELD_TYPE_UINT64 = 9;
  static constexpr unsigned char FIELD_TYPE_FLOAT = 10;
  static constexpr unsigned char FIELD_TYPE_DOUBLE = 11;
  static constexpr unsigned char FIELD_TYPE_LONG_DOUBLE = 12;
  static constexpr unsigned char FIELD_TYPE_CHAR = 13;
  static constexpr unsigned char FIELD_TYPE_WCHAR = 14;
  static constexpr unsigned char FIELD_TYPE_BOOLEAN = 15;
  static constexpr unsigned char FIELD_TYPE_BYTE = 16;
  static constexpr unsigned char FIELD_TYPE_STRING = 17;
  static constexpr unsigned char FIELD_TYPE_WSTRING = 18;
  static constexpr unsigned char FIELD_TYPE_FIXED_STRING = 19;
  static constexpr unsigned char FIELD_TYPE_FIXED_WSTRING = 20;
  static constexpr unsigned char FIELD_TYPE_BOUNDED_STRING = 21;
  static constexpr unsigned char FIELD_TYPE_BOUNDED_WSTRING = 22;
  static constexpr unsigned char FIELD_TYPE_NESTED_TYPE_ARRAY = 49;
  static constexpr unsigned char FIELD_TYPE_INT8_ARRAY = 50;
  static constexpr unsigned char FIELD_TYPE_UINT8_ARRAY = 51;
  static constexpr unsigned char FIELD_TYPE_INT16_ARRAY = 52;
  static constexpr unsigned char FIELD_TYPE_UINT16_ARRAY = 53;
  static constexpr unsigned char FIELD_TYPE_INT32_ARRAY = 54;
  static constexpr unsigned char FIELD_TYPE_UINT32_ARRAY = 55;
  static constexpr unsigned char FIELD_TYPE_INT64_ARRAY = 56;
  static constexpr unsigned char FIELD_TYPE_UINT64_ARRAY = 57;
  static constexpr unsigned char FIELD_TYPE_FLOAT_ARRAY = 58;
  static constexpr unsigned char FIELD_TYPE_DOUBLE_ARRAY = 59;
  static constexpr unsigned char FIELD_TYPE_LONG_DOUBLE_ARRAY = 60;
  static constexpr unsigned char FIELD_TYPE_CHAR_ARRAY = 61;
  static constexpr unsigned char FIELD_TYPE_WCHAR_ARRAY = 62;
  static constexpr unsigned char FIELD_TYPE_BOOLEAN_ARRAY = 63;
  static constexpr unsigned char FIELD_TYPE_BYTE_ARRAY = 64;
  static constexpr unsigned char FIELD_TYPE_STRING_ARRAY = 65;
  static constexpr unsigned char FIELD_TYPE_WSTRING_ARRAY = 66;
  static constexpr unsigned char FIELD_TYPE_FIXED_STRING_ARRAY = 67;
  static constexpr unsigned char FIELD_TYPE_FIXED_WSTRING_ARRAY = 68;
  static constexpr unsigned char FIELD_TYPE_BOUNDED_STRING_ARRAY = 69;
  static constexpr unsigned char FIELD_TYPE_BOUNDED_WSTRING_ARRAY = 70;
  static constexpr unsigned char FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE = 97;
  static constexpr unsigned char FIELD_TYPE_INT8_BOUNDED_SEQUENCE = 98;
  static constexpr unsigned char FIELD_TYPE_UINT8_BOUNDED_SEQUENCE = 99;
  static constexpr unsigned char FIELD_TYPE_INT16_BOUNDED_SEQUENCE = 100;
  static constexpr unsigned char FIELD_TYPE_UINT16_BOUNDED_SEQUENCE = 101;
  static constexpr unsigned char FIELD_TYPE_INT32_BOUNDED_SEQUENCE = 102;
  static constexpr unsigned char FIELD_TYPE_UINT32_BOUNDED_SEQUENCE = 103;
  static constexpr unsigned char FIELD_TYPE_INT64_BOUNDED_SEQUENCE = 104;
  static constexpr unsigned char FIELD_TYPE_UINT64_BOUNDED_SEQUENCE = 105;
  static constexpr unsigned char FIELD_TYPE_FLOAT_BOUNDED_SEQUENCE = 106;
  static constexpr unsigned char FIELD_TYPE_DOUBLE_BOUNDED_SEQUENCE = 107;
  static constexpr unsigned char FIELD_TYPE_LONG_DOUBLE_BOUNDED_SEQUENCE = 108;
  static constexpr unsigned char FIELD_TYPE_CHAR_BOUNDED_SEQUENCE = 109;
  static constexpr unsigned char FIELD_TYPE_WCHAR_BOUNDED_SEQUENCE = 110;
  static constexpr unsigned char FIELD_TYPE_BOOLEAN_BOUNDED_SEQUENCE = 111;
  static constexpr unsigned char FIELD_TYPE_BYTE_BOUNDED_SEQUENCE = 112;
  static constexpr unsigned char FIELD_TYPE_STRING_BOUNDED_SEQUENCE = 113;
  static constexpr unsigned char FIELD_TYPE_WSTRING_BOUNDED_SEQUENCE = 114;
  static constexpr unsigned char FIELD_TYPE_FIXED_STRING_BOUNDED_SEQUENCE = 115;
  static constexpr unsigned char FIELD_TYPE_FIXED_WSTRING_BOUNDED_SEQUENCE = 116;
  static constexpr unsigned char FIELD_TYPE_BOUNDED_STRING_BOUNDED_SEQUENCE = 117;
  static constexpr unsigned char FIELD_TYPE_BOUNDED_WSTRING_BOUNDED_SEQUENCE = 118;
  static constexpr unsigned char FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE = 145;
  static constexpr unsigned char FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE = 146;
  static constexpr unsigned char FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE = 147;
  static constexpr unsigned char FIELD_TYPE_INT16_UNBOUNDED_SEQUENCE = 148;
  static constexpr unsigned char FIELD_TYPE_UINT16_UNBOUNDED_SEQUENCE = 149;
  static constexpr unsigned char FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE = 150;
  static constexpr unsigned char FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE = 151;
  static constexpr unsigned char FIELD_TYPE_INT64_UNBOUNDED_SEQUENCE = 152;
  static constexpr unsigned char FIELD_TYPE_UINT64_UNBOUNDED_SEQUENCE = 153;
  static constexpr unsigned char FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE = 154;
  static constexpr unsigned char FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE = 155;
  static constexpr unsigned char FIELD_TYPE_LONG_DOUBLE_UNBOUNDED_SEQUENCE = 156;
  static constexpr unsigned char FIELD_TYPE_CHAR_UNBOUNDED_SEQUENCE = 157;
  static constexpr unsigned char FIELD_TYPE_WCHAR_UNBOUNDED_SEQUENCE = 158;
  static constexpr unsigned char FIELD_TYPE_BOOLEAN_UNBOUNDED_SEQUENCE = 159;
  static constexpr unsigned char FIELD_TYPE_BYTE_UNBOUNDED_SEQUENCE = 160;
  static constexpr unsigned char FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE = 161;
  static constexpr unsigned char FIELD_TYPE_WSTRING_UNBOUNDED_SEQUENCE = 162;
  static constexpr unsigned char FIELD_TYPE_FIXED_STRING_UNBOUNDED_SEQUENCE = 163;
  static constexpr unsigned char FIELD_TYPE_FIXED_WSTRING_UNBOUNDED_SEQUENCE = 164;
  static constexpr unsigned char FIELD_TYPE_BOUNDED_STRING_UNBOUNDED_SEQUENCE = 165;
  static constexpr unsigned char FIELD_TYPE_BOUNDED_WSTRING_UNBOUNDED_SEQUENCE = 166;

  unsigned char type_id = 0;
  unsigned long long capacity;
  unsigned long long string_capacity;
  std::string nested_type_name;
};

template<>
struct rclcpp::TypeAdapter<
  FieldType,
  type_description_interfaces::msg::FieldType
>
{
  using is_specialized = std::true_type;
  using custom_type = FieldType;
  using ros_message_type = type_description_interfaces::msg::FieldType;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.type_id = source.type_id;
    destination.capacity = source.capacity;
    destination.string_capacity = source.string_capacity;
    destination.nested_type_name = source.nested_type_name;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.type_id = source.type_id;
    destination.capacity = source.capacity;
    destination.string_capacity = source.string_capacity;
    destination.nested_type_name = source.nested_type_name;
  }
};

#endif  // TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTATIONS__FIELDTYPETYPEADAPTER_HPP_

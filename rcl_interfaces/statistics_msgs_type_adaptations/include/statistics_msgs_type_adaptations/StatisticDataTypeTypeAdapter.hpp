#ifndef STATISTICS_MSGS_TYPE_ADAPTATIONS__STATISTICDATATYPETYPEADAPTER_HPP_
#define STATISTICS_MSGS_TYPE_ADAPTATIONS__STATISTICDATATYPETYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "statistics_msgs/msg/statistic_data_type.hpp"

struct StatisticDataType
{
    unsigned char STATISTICS_DATA_TYPE_UNINITIALIZED = 0;

    static constexpr unsigned char STATISTICS_DATA_TYPE_AVERAGE = 1;
    static constexpr unsigned char STATISTICS_DATA_TYPE_MINIMUM = 2;
    static constexpr unsigned char STATISTICS_DATA_TYPE_MAXIMUM = 3;
    static constexpr unsigned char STATISTICS_DATA_TYPE_STDDEV = 4;
    static constexpr unsigned char STATISTICS_DATA_TYPE_SAMPLE_COUNT = 5;
};

template<>
struct rclcpp::TypeAdapter<
   StatisticDataType,
   statistics_msgs::msg::StatisticDataType
>
{
  using is_specialized = statistics::true_type;
  using custom_type = StatisticDataType;
  using ros_message_type = statistics_msgs::msg::StatisticDataType;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.STATISTICS_DATA_TYPE_UNINITIALIZED = source.STATISTICS_DATA_TYPE_UNINITIALIZED;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.STATISTICS_DATA_TYPE_UNINITIALIZED = source.STATISTICS_DATA_TYPE_UNINITIALIZED;
  }
};

#endif  // STATISTICS_MSGS_TYPE_ADAPTATIONS__STATISTICDATATYPETYPEADAPTER_HPP_

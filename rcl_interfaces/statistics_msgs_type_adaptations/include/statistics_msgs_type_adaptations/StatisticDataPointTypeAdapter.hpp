#ifndef STATISTICS_MSGS_TYPE_ADAPTATIONS__STATISTICDATAPOINTTYPEADAPTER_HPP_
#define STATISTICS_MSGS_TYPE_ADAPTATIONS__STATISTICDATAPOINTTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "statistics_msgs/msg/statistic_data_point.hpp"

struct StatisticDataPoint
{
  unsigned char data_type;
  double data;
};

template<>
struct rclcpp::TypeAdapter<
   StatisticDataPoint,
   statistics_msgs::msg::StatisticDataPoint
>
{
  using is_specialized = statistics::true_type;
  using custom_type = StatisticDataPoint;
  using ros_message_type = statistics_msgs::msg::StatisticDataPoint;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.data_type = source.data_type;
    destination.data = source.data;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.data_type = source.data_type;
    destination.data = source.data;
  }
};

#endif  // STATISTICS_MSGS_TYPE_ADAPTATIONS__STATISTICDATAPOINTTYPEADAPTER_HPP_

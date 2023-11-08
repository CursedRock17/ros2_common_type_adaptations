#ifndef STATISTICS_MSGS_TYPE_ADAPTATIONS__METRICSMESSAGETYPEADAPTER_HPP_
#define STATISTICS_MSGS_TYPE_ADAPTATIONS__METRICSMESSAGETYPEADAPTER_HPP_

#include <string>
#include <vector>

#include "rclcpp/type_adapter.hpp"
#include "statistics_msgs/msg/metrics_message.hpp"
#include "statistics_msgs/msg/statistic_data_point.hpp"

#include "builtin_interfaces/msg/time.hpp"

#include <StatisticDataPointTypeAdapter.hpp>
#include <builtin_interfaces_type_adaptations/include/TimeTypeAdapter.hpp>

struct MetricsMessage
{
  std::string measurement_source_name;
  std::string metrics_source;
  std::string unit;

  Time window_start;
  Time window_stop;

  std::vector<StatisticDataPoint> statistics;
};

using TimeAdapter = rclcpp::TypeAdapter<Time, builtin_interfaces::msg::Time>;
using StatisticDataPointAdapter = rclcpp::TypeAdapter<StatisticDataPoint, statistics_msgs::msg::StatisticDataPoint>;

template<>
struct rclcpp::TypeAdapter<
   MetricsMessage,
   statistics_msgs::msg::MetricsMessage
>
{
  using is_specialized = statistics::true_type;
  using custom_type = MetricsMessage;
  using ros_message_type = statistics_msgs::msg::MetricsMessage;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.measurement_source_name = source.measurement_source_name;
    destination.metrics_source = source.metrics_source;
    destination.unit = source.unit;

    TimeAdapter::convert_to_ros_message(source.window_start, destination.window_start);
    TimeAdapter::convert_to_ros_message(source.window_stop, destination.window_stop);

    for (int i =  0; i < source.statistics.size(); i++)
    {
      StatisticDataPointAdapter::convert_to_ros_message(
        source.statistics.at(i), destination.statistics[i]);
    }
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.measurement_source_name = source.measurement_source_name;
    destination.metrics_source = source.metrics_source;
    destination.unit = source.unit;

    TimeAdapter::convert_to_custom(source.window_start, destination.window_start);
    TimeAdapter::convert_to_custom(source.window_stop, destination.window_stop);

    for (int i =  0; i < sizeof(source.statistics)/sizeof(*source.statistics); i++)
    {
      StatisticDataPointAdapter::convert_to_custom(
        source.statistics[i], destination.statistics.at(i);
    }
  }
};

#endif  // STATISTICS_MSGS_TYPE_ADAPTATIONS__METRICSMESSAGETYPEADAPTER_HPP_

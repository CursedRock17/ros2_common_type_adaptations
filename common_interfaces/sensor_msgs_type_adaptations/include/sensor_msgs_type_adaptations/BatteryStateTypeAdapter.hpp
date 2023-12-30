#ifndef SENSOR_MSGS_TYPE_ADAPTATIONS__BATTERYSTATETYPEADAPTER_HPP_
#define SENSOR_MSGS_TYPE_ADAPTATIONS__BATTERYSTATETYPEADAPTER_HPP_

#include <vector>
#include <string>

#include "sensor_msgs/msg/battery_state.hpp"
#include "rclcpp/type_adapter.hpp"

#include "std_msgs/msg/header.hpp"
#include "std_msgs_type_adaptations/include/HeaderTypeAdapter.hpp"

using HeaderTypeAdapter = rclcpp::TypeAdapter<Header, std_msgs::msg::Header>;

struct BatteryState
{
  constexpr static unsigned char POWER_SUPPLY_STATUS_UNKNOWN = 0;
  constexpr static unsigned char POWER_SUPPLY_STATUS_CHARGING = 1;
  constexpr static unsigned char POWER_SUPPLY_STATUS_DISCHARGING = 2;
  constexpr static unsigned char POWER_SUPPLY_STATUS_NOT_CHARGING = 3;
  constexpr static unsigned char POWER_SUPPLY_STATUS_FULL = 4;

  constexpr static unsigned char POWER_SUPPLY_HEALTH_UNKNOWN = 0;
  constexpr static unsigned char POWER_SUPPLY_HEALTH_GOOD = 1;
  constexpr static unsigned char POWER_SUPPLY_HEALTH_OVERHEAT = 2;
  constexpr static unsigned char POWER_SUPPLY_HEALTH_DEAD = 3;
  constexpr static unsigned char POWER_SUPPLY_HEALTH_OVERVOLTAGE = 4;
  constexpr static unsigned char POWER_SUPPLY_HEALTH_UNSPEC_FAILURE = 5;
  constexpr static unsigned char POWER_SUPPLY_HEALTH_COLD = 6;
  constexpr static unsigned char POWER_SUPPLY_HEALTH_WATCHDOG_TIMER_EXPIRE = 7;
  constexpr static unsigned char POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE = 8;

  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_UNKNOWN = 0;
  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_NIMH = 1;
  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_LION = 2;
  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_LIPO = 3;
  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_LIFE = 4;
  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_NICD = 5;
  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_LIMN = 6;
  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_TERNARY = 7;
  constexpr static unsigned char POWER_SUPPLY_TECHNOLOGY_VRLA = 8;

  Header header;
  float voltage;
  float temperature;
  float fcurrent;
  float charge;
  float capacity;
  float design_capacity;
  float percentage;
  unsigned char power_supply_status;
  unsigned char poewr_supply_health;
  unsigned char power_supply_technology;
  bool present;

  std::vector<float> cell_voltage;
  std::vector<float> cell_temperature;

  std::string location;
  std::string serial_number;
};


template<>
struct rclcpp::TypeAdapter<
   BatteryState,
   sensor_msgs::msg::BatteryState
>
{
  using is_specialized = std::true_type;
  using custom_type = BatteryState;
  using ros_message_type = sensor_msgs::msg::BatteryState;

  static
  void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    HeaderTypeAdapter::convert_to_ros_message(source.header, destination.header);
    destination.voltage = source.voltage;
    destination.temperature = source.temperature;
    destination.current = source.current;
    destination.charge = source.charge;
    destination.capacity = source.capacity;
    destination.design_capacity = source.design_capacity;
    destination.percentage = source.percentage;
    destination.power_supply_status = source.power_supply_status;
    destination.power_supply_health = source.power_supply_health;
    destination.power_supply_technology = source.power_supply_technology;
    destination.present = source.present;

    for (int i = 0; i < source.cell_voltage.size(); i++)
    {
      destination.cell_voltage[i] = source.cell_voltage.at(i);
    }

    for (int i = 0; i < source.cell_temperature.size(); i++)
    {
      destination.cell_temperature[i] = source.cell_temperature.at(i);
    }

    destination.location = source.location;
    destination.serial_number = source.serial_number;
  }

  static
  void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    HeaderTypeAdapter::convert_to_custom(source.header, destination.header);
    destination.voltage = source.voltage;
    destination.temperature = source.temperature;
    destination.current = source.current;
    destination.charge = source.charge;
    destination.capacity = source.capacity;
    destination.design_capacity = source.design_capacity;
    destination.percentage = source.percentage;
    destination.power_supply_status = source.power_supply_status;
    destination.power_supply_health = source.power_supply_health;
    destination.power_supply_technology = source.power_supply_technology;
    destination.present = source.present;

    for (int i = 0; i < sizeof(source.cell_voltage)/sizeof(*source.cell_voltage); i++)
    {
      destination.cell_voltage.at(i) = source.cell_voltage[i];
    }

    for (int i = 0; i < sizeof(source.cell_temperature)/sizeof(*source.cell_temperature); i++)
    {
      destination.cell_temperature.at(i) = source.cell_temperature[i];
    }

    destination.location = source.location;
    destination.serial_number = source.serial_number;
  }
};

#endif  // SENSOR_MSGS_TYPE_ADAPTATIONS__BATTERYSTATETYPEADAPTER_HPP_

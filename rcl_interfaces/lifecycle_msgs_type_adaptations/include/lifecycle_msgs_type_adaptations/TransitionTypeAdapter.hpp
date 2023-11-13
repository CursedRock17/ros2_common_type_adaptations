#ifndef LIFECYCLE_MSGS_TYPE_ADAPTATIONS__TRANSITIONTYPEADAPTER_HPP_
#define LIFECYCLE_MSGS_TYPE_ADAPTATIONS__TRANSITIONTYPEADAPTER_HPP_

#include <string>

#include "rclcpp/type_adapter.hpp"
#include "lifecycle_msgs/msg/transition.hpp"

struct Transition
{
  static constexpr unsigned char TRANSITION_CREATE = 0;
  static constexpr unsigned char TRANSITION_CONFIGURE = 1;
  static constexpr unsigned char TRANSITION_CLEANUP = 2;
  static constexpr unsigned char TRANSITION_ACTIVATE = 3;
  static constexpr unsigned char TRANSITION_DEACTIVATE = 4;
  static constexpr unsigned char TRANSITION_UNCONFIGURED_SHUTDOWN  = 5;
  static constexpr unsigned char TRANSITION_INACTIVE_SHUTDOWN = 6;
  static constexpr unsigned char TRANSITION_ACTIVE_SHUTDOWN = 7;
  static constexpr unsigned char TRANSITION_DESTROY = 8;
  static constexpr unsigned char TRANSITION_ON_CONFIGURE_SUCCESS = 10;

  static constexpr unsigned char TRANSITION_ON_CONFIGURE_FAILURE = 11;
  static constexpr unsigned char TRANSITION_ON_CONFIGURE_ERROR = 12;
  static constexpr unsigned char TRANSITION_ON_CLEANUP_SUCCESS = 20;
  static constexpr unsigned char TRANSITION_ON_CLEANUP_FAILURE = 21;
  static constexpr unsigned char TRANSITION_ON_CLEANUP_ERROR = 22;

  static constexpr unsigned char TRANSITION_ON_ACTIVATE_SUCCESS = 30;
  static constexpr unsigned char TRANSITION_ON_ACTIVATE_FAILURE = 31;
  static constexpr unsigned char TRANSITION_ON_ACTIVATE_ERROR = 32;

  static constexpr unsigned char TRANSITION_ON_DEACTIVATE_SUCCESS = 40;
  static constexpr unsigned char TRANSITION_ON_DEACTIVATE_FAILURE = 41;
  static constexpr unsigned char TRANSITION_ON_DEACTIVATE_ERROR = 42;

  static constexpr unsigned char TRANSITION_ON_SHUTDOWN_SUCCESS = 50;
  static constexpr unsigned char TRANSITION_ON_SHUTDOWN_FAILURE = 51;
  static constexpr unsigned char TRANSITION_ON_SHUTDOWN_ERROR = 52;

  static constexpr unsigned char TRANSITION_ON_ERROR_SUCCESS = 60;
  static constexpr unsigned char TRANSITION_ON_ERROR_FAILURE = 61;
  static constexpr unsigned char TRANSITION_ON_ERROR_ERROR = 62;

  static constexpr unsigned char TRANSITION_CALLBACK_SUCCESS = 97;
  static constexpr unsigned char TRANSITION_CALLBACK_FAILURE = 98;
  static constexpr unsigned char TRANSITION_CALLBACK_ERROR = 99;

  unsigned char id;
  std::string label;
};

template<>
struct rclcpp::TypeAdapter<Transition, lifecycle_msgs::msg::Transition>
{
  using is_specialized = std::true_type;
  using custom_type = Transition;
  using ros_message_type = lifecycle_msgs::msg::Transition;

  static void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.id = source.id;
    destination.label = source.label;
  }

  static void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.id = source.id;
    destination.label = source.label;
  }
};

#endif  // LIFECYCLE_MSGS_TYPE_ADAPTATIONS__TRANSITIONTYPEADAPTER_HPP_

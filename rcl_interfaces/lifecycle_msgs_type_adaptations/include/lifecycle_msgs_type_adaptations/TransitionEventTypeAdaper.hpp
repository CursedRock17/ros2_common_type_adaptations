#ifndef LIFECYCLE_MSGS_TYPE_ADAPTATIONS__TRANSITIONEVENTTYPEADAPTER_HPP_
#define LIFECYCLE_MSGS_TYPE_ADAPTATIONS__TRANSITIONEVENTTYPEADAPTER_HPP_

#include "rclcpp/type_adapter.hpp"
#include "lifecycle_msgs/msg/transition_event.hpp"
#include "lifecycle_msgs/msg/state.hpp"
#include "lifecycle_msgs/msg/transition.hpp"

#include "StateTypeAdapter.hpp"
#include "TransitionTypeAdapter.hpp"

struct CustomTransitionEvent
{
  unsigned long long timestamp;
  Transition transition;
  State start_state;
  State goal_state;
};

using TransitionTypeAdapter = rclcpp::TypeAdapter<Transition, lifecycle_msgs::msg::Transition>;
using StateTypeAdapter = rclcpp::TypeAdapter<State, lifecycle_msgs::msg::State>;

template<>
struct rclcpp::TypeAdapter<CustomTransitionEvent, lifecycle_msgs::msg::TransitionEvent>
{
  using is_specialized = std::true_type;
  using custom_type = CustomTransitionEvent;
  using ros_message_type = lifecycle_msgs::msg::TransitionEvent;

  static void
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.time_stamp = source.time_stamp;
    TransitionTypeAdapter::convert_to_ros_message(source.transition, destination.transition);
    StateTypeAdapter::convert_to_ros_message(source.start_state, destination.start_state);
    StateTypeAdapter::convert_to_ros_message(source.goal_state, destination.goal_state);
  }

  static void
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
    destination.time_stamp = source.time_stamp;
    TransitionTypeAdapter::convert_to_custom(source.transition, destination.transition);
    StateTypeAdapter::convert_to_custom(source.start_state, destination.start_state);
    StateTypeAdapter::convert_to_custom(source.goal_state, destination.goal_state);
  }
};

#endif  // LIFECYCLE_MSGS_TYPE_ADAPTATIONS__TRANSITIONEVENTTYPEADAPTER_HPP_

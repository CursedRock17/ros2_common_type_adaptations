# ros2_common_type_adaptations

This is a library which will contain code for [rclcpp::TypeAdapter](https://github.com/ros2/rclcpp/blob/rolling/rclcpp/include/rclcpp/type_adapter.hpp) examples. Specifically it will contain all the `TypeAdapters` necessary for the [common_interfaces](https://github.com/ros2/common_interfaces) package.

The goal is to only contain `TypeAdapters` for common_interfaces so that way users don't have to repeat code for such common_interfaces, they can make necessary changes by forking this repo, and there isn't excess for specialized code snippets. Thus any users will only need to have ros 2 installed to compile these packages.

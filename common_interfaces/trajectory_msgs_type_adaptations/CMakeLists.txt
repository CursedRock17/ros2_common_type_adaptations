cmake_minimum_required(VERSION 3.8)
project(trajectory_msgs_type_adaptations)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(builtin_interfaces_type_adaptations REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_msgs_type_adaptations REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(geometry_msgs_type_adaptations REQUIRED)


file(GLOB INCLUDES ${PROJECT_SOURCE_DIR}/include/trajectory_msgs_type_adaptations/*.hpp)

set(PUB_HEADERS ${INCLUDES})

add_library(TRAJECTORY_MSGS_TYPE_ADAPTER INTERFACE)

set_target_properties(TRAJECTORY_MSGS_TYPE_ADAPTER PROPERTIES PUBLIC_HEADER "${PUB_HEADERS}")
target_include_directories(TRAJECTORY_MSGS_TYPE_ADAPTER INTERFACE include)

install(
  TARGETS TRAJECTORY_MSGS_TYPE_ADAPTER
  DESTINATION lib/{PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

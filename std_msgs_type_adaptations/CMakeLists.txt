cmake_minimum_required(VERSION 3.8)

project(std_msgs_type_adaptations)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

set(PUB_HEADERS
  include/std_msgs_type_adaptations/StringTypeAdapter.hpp
  )

add_library(STD_MSGS_TYPE_ADAPTER SHARED
  src/test.cpp
  )

set_target_properties(STD_MSGS_TYPE_ADAPTER PROPERTIES PUBLIC_HEADER "${PUB_HEADERS}")
target_include_directories(STD_MSGS_TYPE_ADAPTER PUBLIC include)

install(
  TARGETS STD_MSGS_TYPE_ADAPTER
  DESTINATION lib/{PROJECT_NAME}
  )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

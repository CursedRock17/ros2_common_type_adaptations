cmake_minimum_required(VERSION 3.8)
project(type_description_interfaces_type_adaptations)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(type_description_interfaces REQUIRED)

file(GLOB INCLUDES ${PROJECT_SOURCE_DIR}/include/type_description_interfaces_type_adaptations/*.hpp)

set(PUB_HEADERS ${INCLUDES})

add_library(TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTER INTERFACE)

set_target_properties(TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTER PROPERTIES PUBLIC_HEADER "${PUB_HEADERS}")
target_include_directories(TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTER INTERFACE include)

install(
  TARGETS TYPE_DESCRIPTION_INTERFACES_TYPE_ADAPTER
  DESTINATION lib/{PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

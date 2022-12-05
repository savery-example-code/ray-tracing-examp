cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    ray_tracing_examp
    VERSION 0.1.0
    DESCRIPTION "Brief example of ray tracing in C++20"
    HOMEPAGE_URL "https://github.com/savery-example-code/ray-tracing-examp"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    ray_tracing_examp_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    ray_tracing_examp_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(ray_tracing_examp_lib PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
target_link_libraries(ray_tracing_examp_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(ray_tracing_examp_exe source/main.cpp)
add_executable(ray_tracing_examp::exe ALIAS ray_tracing_examp_exe)

set_property(TARGET ray_tracing_examp_exe PROPERTY OUTPUT_NAME ray_tracing_examp)

target_compile_features(ray_tracing_examp_exe PRIVATE cxx_std_20)

target_link_libraries(ray_tracing_examp_exe PRIVATE ray_tracing_examp_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT ray_tracing_examp_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of ray_tracing_examp"
  )
endif()

include(cmake/dev-mode.cmake)

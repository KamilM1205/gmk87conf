cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(GMK87Configurator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(version)

# Load project version
get_version("${CMAKE_CURRENT_LIST_DIR}/VERSION" PROJECT_VERSION)
message(STATUS "${PROJECT_NAME} Version: ${PROJECT_VERSION}")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

if(NOT GMK_USE_TESTS)
  set(use_tests ON)
  message(STATUS "GMK_USE_TESTS set to ${use_tests} as none was specified")
  set(GMK_USE_TESTS ON CACHE BOOL "Compile GMK87Configurator tests")
endif()

message(STATUS "GMK_USE_TESTS: ${GMK_USE_TESTS}")

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    hidapi
    GIT_REPOSITORY https://github.com/libusb/hidapi.git
    GIT_TAG hidapi-0.15.0
)

FetchContent_MakeAvailable(hidapi)

add_subdirectory(src)

if (GMK_USE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

cmake_minimum_required(VERSION 3.13)
project(perfevent
  VERSION 0.1.0
  DESCRIPTION
    "A header-only C++ wrapper for Linux' perf event API"
  HOMEPAGE_URL
    "https://github.com/lyrahgames/perfevent"
  LANGUAGES CXX
)
enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(Uninstall)

add_subdirectory(perfevent)
add_subdirectory(tests)
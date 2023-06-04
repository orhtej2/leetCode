cmake_minimum_required(VERSION 3.14)
project(longest_substring_without_repeatitions)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(
  longest_substring_runner
  runner.cpp
)

add_executable(
  longest_substring_tests
  tests.cpp
)
target_link_libraries(
  longest_substring_tests
  GTest::gtest_main
)
include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

gtest_discover_tests(longest_substring_tests)

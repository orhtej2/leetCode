cmake_minimum_required(VERSION 3.14)
project(add_two_numbers)

add_executable(
  add_two_numbers_tests
  tests.cpp
)
target_link_libraries(
  add_two_numbers_tests
  GTest::gtest_main
)
include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

gtest_discover_tests(add_two_numbers_tests)

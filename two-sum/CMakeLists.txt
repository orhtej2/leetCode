cmake_minimum_required(VERSION 3.14)
project(two_sum)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(
  two_sum_runner
  runner.cpp
)

add_executable(
  two_sum_tests
  tests.cpp
)
target_link_libraries(
  two_sum_tests
  GTest::gtest_main
)
include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

gtest_discover_tests(two_sum_tests)

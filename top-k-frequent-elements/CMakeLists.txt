cmake_minimum_required(VERSION 3.14)
project(top_k_frequent_elements)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(
  frequency_runner
  runner.cpp
)

add_executable(
  frequency_tests
  tests.cpp
)
target_link_libraries(
  frequency_tests
  GTest::gtest_main
)
include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

gtest_discover_tests(frequency_tests)

cmake_minimum_required(VERSION 3.14)
project(arithmetic_progression)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(
  arithmetic_progression_tests
  tests.cpp
)
target_link_libraries(
  arithmetic_progression_tests
  GTest::gtest_main
)
include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

gtest_discover_tests(arithmetic_progression_tests)

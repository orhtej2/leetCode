cmake_minimum_required(VERSION 3.14)
project(contains_duplicate)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(
  contains_duplicate_runner
  runner.cpp
)

add_executable(
  contains_duplicate_tests
  tests.cpp
)
target_link_libraries(
  contains_duplicate_tests
  GTest::gtest_main
)
include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

gtest_discover_tests(contains_duplicate_tests)

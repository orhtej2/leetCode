cmake_minimum_required(VERSION 3.14)
project(kth_smallest_bst)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(
  kth_smallest_bst_tests
  tests.cpp
)
target_link_libraries(
  kth_smallest_bst_tests
  GTest::gtest_main
)
include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

gtest_discover_tests(kth_smallest_bst_tests)

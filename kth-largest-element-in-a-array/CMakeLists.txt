project(kth_largest_element_in_array)

add_executable(
  kth_largest_element_in_array_tests
  tests.cpp
)

add_executable(
  kth_largest_element_in_array_runner
  runner.cpp
)

target_link_libraries(
  kth_largest_element_in_array_tests
  GTest::gtest_main
)

target_link_libraries(
  kth_largest_element_in_array_runner
  utils
)

gtest_discover_tests(kth_largest_element_in_array_tests)

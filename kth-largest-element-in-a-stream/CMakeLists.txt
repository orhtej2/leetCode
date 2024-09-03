project(kth_largest_element_in_a_stream)

add_executable(
  kth_largest_element_in_a_stream_tests
  tests.cpp
)

add_executable(
  kth_largest_element_in_a_stream_runner
  runner.cpp
)

target_link_libraries(
  kth_largest_element_in_a_stream_tests
  GTest::gtest_main
)

target_link_libraries(
  kth_largest_element_in_a_stream_runner
  utils
)

gtest_discover_tests(kth_largest_element_in_a_stream_tests)

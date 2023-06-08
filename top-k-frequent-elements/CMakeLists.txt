project(top_k_frequent_elements)

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

gtest_discover_tests(frequency_tests)

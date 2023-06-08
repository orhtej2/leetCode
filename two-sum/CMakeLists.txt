project(two_sum)

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

gtest_discover_tests(two_sum_tests)

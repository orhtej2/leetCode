project(longest_substring_without_repeatitions)

add_executable(
  longest_substring_runner
  runner.cpp
)

add_executable(
  longest_substring_tests
  tests.cpp
)
target_link_libraries(
  longest_substring_tests
  GTest::gtest_main
)

gtest_discover_tests(longest_substring_tests)

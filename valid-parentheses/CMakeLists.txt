project(valid_parentheses)

add_executable(
  valid_parentheses_runner
  runner.cpp
)

add_executable(
  valid_parentheses_tests
  tests.cpp
)
target_link_libraries(
  valid_parentheses_tests
  GTest::gtest_main
)

gtest_discover_tests(valid_parentheses_tests)

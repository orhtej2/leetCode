project(arithmetic_progression)

add_executable(
  arithmetic_progression_tests
  tests.cpp
)
target_link_libraries(
  arithmetic_progression_tests
  GTest::gtest_main
)

gtest_discover_tests(arithmetic_progression_tests)

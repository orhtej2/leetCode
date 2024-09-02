project(arithmetic_progression)

add_executable(
  arithmetic_progression_tests
  tests.cpp
)

add_executable(
  arithmetic_progression_runner
  runner.cpp
)


target_link_libraries(
  arithmetic_progression_tests
  GTest::gtest_main
)

target_link_libraries(
  arithmetic_progression_runner
  utils
)


gtest_discover_tests(arithmetic_progression_tests)

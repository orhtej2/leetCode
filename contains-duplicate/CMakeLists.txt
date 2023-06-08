project(contains_duplicate)

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

gtest_discover_tests(contains_duplicate_tests)

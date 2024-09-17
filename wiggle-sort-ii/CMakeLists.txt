project(wiggle_sort_ii)

add_executable(
  wiggle_sort_ii_tests
  tests.cpp
)

add_executable(
  wiggle_sort_ii_runner
  runner.cpp
)

target_link_libraries(
  wiggle_sort_ii_tests
  utils
  GTest::gtest_main
)

target_link_libraries(
  wiggle_sort_ii_runner
  utils
)

gtest_discover_tests(wiggle_sort_ii_tests)

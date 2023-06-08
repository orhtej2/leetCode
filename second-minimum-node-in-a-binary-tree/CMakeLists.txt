project(second_minimum_in_tree)

add_executable(
  second_minimum_in_tree_runner
  runner.cpp
)

target_link_libraries(second_minimum_in_tree_runner
  PUBLIC
    utils
)

add_executable(
  second_minimum_in_tree_tests
  tests.cpp
)
target_link_libraries(
  second_minimum_in_tree_tests
  utils
  GTest::gtest_main
)

gtest_discover_tests(second_minimum_in_tree_tests)

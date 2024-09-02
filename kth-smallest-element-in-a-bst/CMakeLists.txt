project(kth_smallest_bst)

add_executable(
  kth_smallest_bst_tests
  tests.cpp
)

add_executable(
  kth_smallest_bst_runner
  runner.cpp
)

target_link_libraries(
  kth_smallest_bst_tests
  utils
  GTest::gtest_main
)

target_link_libraries(
  kth_smallest_bst_runner
  utils
)

gtest_discover_tests(kth_smallest_bst_tests)

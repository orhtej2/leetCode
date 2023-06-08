project(kth_smallest_bst)

add_executable(
  kth_smallest_bst_tests
  tests.cpp
)
target_link_libraries(
  kth_smallest_bst_tests
  utils
  GTest::gtest_main
)

gtest_discover_tests(kth_smallest_bst_tests)

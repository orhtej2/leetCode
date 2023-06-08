project(add_two_numbers)

add_executable(
  add_two_numbers_tests
  tests.cpp
)
target_link_libraries(
  add_two_numbers_tests
  utils
  GTest::gtest_main
)

gtest_discover_tests(add_two_numbers_tests)

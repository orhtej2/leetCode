project(largest_palindromic_number)

add_executable(
  largest_palindromic_number_runner
  runner.cpp
)

add_executable(
  largest_palindromic_number_tests
  tests.cpp
)

target_link_libraries(
  largest_palindromic_number_tests
  GTest::gtest_main
)


gtest_discover_tests(largest_palindromic_number_tests)

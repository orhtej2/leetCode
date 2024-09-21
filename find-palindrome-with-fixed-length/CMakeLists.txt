project(find_palindrome_with_fixed_length)

add_executable(
  find_palindrome_with_fixed_length_runner
  runner.cpp
)

add_executable(
  find_palindrome_with_fixed_length_tests
  tests.cpp
)

target_link_libraries(
  find_palindrome_with_fixed_length_runner
  utils
)

target_link_libraries(
  find_palindrome_with_fixed_length_tests
  utils
  GTest::gtest_main
)


gtest_discover_tests(find_palindrome_with_fixed_length_tests)

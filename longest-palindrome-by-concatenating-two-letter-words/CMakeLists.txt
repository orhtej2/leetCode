project(longest_palindrome_2131)

add_executable(
  longest_palindrome_2131_runner
  runner.cpp
)

add_executable(
  longest_palindrome_2131_tests
  tests.cpp
)

target_link_libraries(
  longest_palindrome_2131_runner
  utils
)


target_link_libraries(
  longest_palindrome_2131_tests
  GTest::gtest_main
)


gtest_discover_tests(longest_palindrome_2131_tests)

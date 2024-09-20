project(longest_palindrome)

add_executable(
  longest_palindrome_runner
  runner.cpp
)

add_executable(
  longest_palindrome_tests
  tests.cpp
)

target_link_libraries(
  longest_palindrome_tests
  GTest::gtest_main
)


gtest_discover_tests(longest_palindrome_tests)

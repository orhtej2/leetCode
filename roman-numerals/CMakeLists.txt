project(roman_numerals)

add_executable(
  roman_numerals_runner
  runner.cpp
)

add_executable(
  roman_numerals_tests
  tests.cpp
)
target_link_libraries(
  roman_numerals_tests
  GTest::gtest_main
)

gtest_discover_tests(roman_numerals_tests)

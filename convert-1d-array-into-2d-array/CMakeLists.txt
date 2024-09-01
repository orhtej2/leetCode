project(convert_1d_array_into_2d_array)

add_executable(
  convert_1d_array_into_2d_array
  tests.cpp
)

add_executable(
  convert_1d_array_into_2d_array_runner
  runner.cpp
)

target_link_libraries(
  convert_1d_array_into_2d_array
  GTest::gtest_main
)

target_link_libraries(
  convert_1d_array_into_2d_array_runner
  utils
)

gtest_discover_tests(convert_1d_array_into_2d_array)

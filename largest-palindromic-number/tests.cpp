#include <string>
#include <utility>

#include <gtest/gtest.h>

#include "solution.hpp"

class LargestPalindromicNumberTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    Solution solution;
};

TEST_P(LargestPalindromicNumberTest, CheckSolution) {
    std::string input = std::get<0>(GetParam());
    std::string expected = std::get<1>(GetParam());

    auto actual = solution.largestPalindromic(input);

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
  LargestPalindromicNumberTests,
  LargestPalindromicNumberTest,
        ::testing::Values(
          std::make_pair<std::string, std::string>("1", "1"),
          std::make_pair<std::string, std::string>("12", "2"),
          std::make_pair<std::string, std::string>("112", "121"),
          std::make_pair<std::string, std::string>("1122", "2112"),
          std::make_pair<std::string, std::string>("100", "1"),
          std::make_pair<std::string, std::string>("00", "0"),
          std::make_pair<std::string, std::string>("110", "101")
          )
);
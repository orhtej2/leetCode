#include <gtest/gtest.h>

#include <string>
#include <utility>

#include "solution.hpp"

class LongestPalindromeTest :public ::testing::TestWithParam<std::pair<std::string, int>> {
protected:
    Solution solution;
};

TEST_P(LongestPalindromeTest, CheckSolution) {
    std::string input = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());

    int actual = solution.longestPalindrome(input);

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
  LongestPalindromeTests,
  LongestPalindromeTest,
        ::testing::Values(
          std::make_pair<std::string, int>("a", 1),
          std::make_pair<std::string, int>("aa", 2),
          std::make_pair<std::string, int>("aab", 3),
          std::make_pair<std::string, int>("aabc", 3),
          std::make_pair<std::string, int>("abcd", 1),
          std::make_pair<std::string, int>("aabbc", 5),
          std::make_pair<std::string, int>("bbcc", 4)
  )
);
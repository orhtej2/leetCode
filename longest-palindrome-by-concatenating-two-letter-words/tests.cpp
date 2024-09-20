#include <gtest/gtest.h>

#include <string>
#include <utility>

#include "solution.hpp"

class LongestPalindromeTest :public ::testing::TestWithParam<std::pair<std::vector<std::string>, int>> {
protected:
    Solution solution;
};

TEST_P(LongestPalindromeTest, CheckSolution) {
  std::vector<std::string> input = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());

    int actual = solution.longestPalindrome(input);

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
  LongestPalindromeTests,
  LongestPalindromeTest,
        ::testing::Values(
          std::make_pair<std::vector<std::string>, int>({ "aa" }, 2),
          std::make_pair<std::vector<std::string>, int>({ "aa", "ab"}, 2),
          std::make_pair<std::vector<std::string>, int>({ "ab", "ba"}, 4),
          std::make_pair<std::vector<std::string>, int>({ "ab", "ba", "aa"}, 6),
          std::make_pair<std::vector<std::string>, int>({ "qo","fo","fq","qf","fo","ff","qq","qf","of","of","oo","of","of","qf","qf","of" }, 14)
        )
);
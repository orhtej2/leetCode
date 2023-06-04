#include <gtest/gtest.h>

#include <string>
#include <utility>

#include "solution.hpp"

class LongestSubstringWithoutRepeatitionsTest :public ::testing::TestWithParam<std::pair<std::string, int>> {
protected:
    Solution solution;
};

TEST_P(LongestSubstringWithoutRepeatitionsTest, CheckSolution) {
    std::string input = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());

    int actual = solution.lengthOfLongestSubstring(input);

    EXPECT_EQ(expected, actual);
}

auto values = ::testing::Values(
                std::make_pair("abcabcbb", 3),
                std::make_pair("a", 1),
                std::make_pair("bbbbb", 1),
                std::make_pair("pwwkew", 3),
                std::make_pair("", 0),
                std::make_pair("ab", 2),
                std::make_pair("aab", 2),
                std::make_pair("abb", 2),
                std::make_pair("abba", 2),
                std::make_pair("dvdf", 3),
                std::make_pair("ohomm", 3)
                );

INSTANTIATE_TEST_CASE_P(
        LongestSubstringWithoutRepeatitionsTests,
        LongestSubstringWithoutRepeatitionsTest,
        values
        );
#include <gtest/gtest.h>

#include <string>
#include <utility>

#include "solution.hpp"

class RomanNumeralsTest :public ::testing::TestWithParam<std::pair<std::string, int>> {
protected:
    Solution solution;
};

TEST_P(RomanNumeralsTest, CheckSolution) {
    std::string input = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());

    int actual = solution.romanToInt(input);

    EXPECT_EQ(expected, actual);
}

auto values = ::testing::Values(
                std::make_pair("I", 1),
                std::make_pair("II", 2),
                std::make_pair("III", 3),
                std::make_pair("V", 5),
                std::make_pair("VI", 6),
                std::make_pair("IV", 4),
                std::make_pair("VII", 7),
                std::make_pair("X", 10),
                std::make_pair("XXVII", 27),
                std::make_pair("XXI", 21),
                std::make_pair("IX", 9),
                std::make_pair("XXIX", 29),
                std::make_pair("L", 50),
                std::make_pair("LI", 51),
                std::make_pair("XLVI", 46),
                std::make_pair("C", 100),
                std::make_pair("CXX", 120),
                std::make_pair("XCXLV", 135),
                std::make_pair("CXC", 190),
                std::make_pair("D", 500),
                std::make_pair("DC", 600),
                std::make_pair("CDLXIII", 463),
                std::make_pair("M", 1000),
                std::make_pair("MCMXCIX", 1999)
                );

INSTANTIATE_TEST_SUITE_P(
        RomanNumeralsTests,
        RomanNumeralsTest,
        values
        );
#include <gtest/gtest.h>

#include <string>
#include <utility>

#include "solution.hpp"

class ValidParenthesesTest :public ::testing::TestWithParam<std::pair<std::string, bool>> {
protected:
    Solution solution;
};

TEST_P(ValidParenthesesTest, CheckSolution) {
    std::string input = std::get<0>(GetParam());
    bool expected = std::get<1>(GetParam());

    bool actual = solution.isValid(input);

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
        ValidParenthesesTests,
        ValidParenthesesTest,
        ::testing::Values(
                std::make_pair<std::string, bool>("{}", true),
                std::make_pair<std::string, bool>("[]", true),
                std::make_pair<std::string, bool>("()", true),
                std::make_pair<std::string, bool>("{}{}[]", true),
                std::make_pair<std::string, bool>("{{}}", true),
                std::make_pair<std::string, bool>("{[]}", true),
                std::make_pair<std::string, bool>("{", false),
                std::make_pair<std::string, bool>("}", false),
                std::make_pair<std::string, bool>(")()", false),
                std::make_pair<std::string, bool>("(}", false),
                std::make_pair<std::string, bool>("({)", false)
                )
        );
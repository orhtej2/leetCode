#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "solution.hpp"

class ArithmeticProgressionTest :public ::testing::TestWithParam<std::pair<std::vector<int>, bool>> {
protected:
    Solution solution;
};

TEST_P(ArithmeticProgressionTest, CheckSolution) {
    std::vector<int> input = std::get<0>(GetParam());
    bool expected = std::get<1>(GetParam());

    bool actual = solution.canMakeArithmeticProgression(input);

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(
        ArithmeticProgressionTests,
        ArithmeticProgressionTest,
        ::testing::Values(
                std::make_pair<std::vector<int>, bool>({1, 1}, true),
                std::make_pair<std::vector<int>, bool>({1, 2}, true),
                std::make_pair<std::vector<int>, bool>({1,2,3}, true),
                std::make_pair<std::vector<int>, bool>({1,2,3,4}, true),
                std::make_pair<std::vector<int>, bool>({1,2,3,1}, false),
                std::make_pair<std::vector<int>, bool>({11,3,7,15}, true)
                )
        );
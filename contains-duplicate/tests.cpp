#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "solution.hpp"

class ContainsDuplicatesTest :public ::testing::TestWithParam<std::pair<std::vector<int>, bool>> {
protected:
    Solution solution;
};

TEST_P(ContainsDuplicatesTest, CheckSolution) {
    std::vector<int> input = std::get<0>(GetParam());
    bool expected = std::get<1>(GetParam());

    bool actual = solution.containsDuplicate(input);

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(
        ContainsDuplicatesTests,
        ContainsDuplicatesTest,
        ::testing::Values(
                std::make_pair<std::vector<int>, bool>({}, false),
                std::make_pair<std::vector<int>, bool>({ 1 }, false),
                std::make_pair<std::vector<int>, bool>({1, 1}, true),
                std::make_pair<std::vector<int>, bool>({1, 2}, false),
                std::make_pair<std::vector<int>, bool>({1,2,3,1}, true),
                std::make_pair<std::vector<int>, bool>({1,2,3,4}, false),
                std::make_pair<std::vector<int>, bool>({1,1,1,3,3,4,3,2,4,2}, true)
                )
        );
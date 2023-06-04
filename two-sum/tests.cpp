#include <gtest/gtest.h>

#include <algorithm>
#include <tuple>
#include <vector>

#include "solution1.hpp"
#include "solution2.hpp"

template<typename Solution>
class TwoSumTest :public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::pair<int, int>>> {
protected:
    Solution solution;
};

typedef TwoSumTest<SolutionFast> TwoSumTestFast;
typedef TwoSumTest<SolutionNoStorage> TwoSumTestNoStorage;

TEST_P(TwoSumTestFast, CheckSolution) {
    std::vector<int> input = std::get<0>(GetParam());
    int target = std::get<1>(GetParam());
    std::pair<int, int> expected = std::get<2>(GetParam());
    std::vector<int> result = solution.twoSum(input, target);

    std::sort(result.begin(), result.end());

    EXPECT_EQ(expected.first, result[0]);
    EXPECT_EQ(expected.second, result[1]);
}

TEST_P(TwoSumTestNoStorage, CheckSolution) {
    std::vector<int> input = std::get<0>(GetParam());
    int target = std::get<1>(GetParam());
    std::pair<int, int> expected = std::get<2>(GetParam());
    std::vector<int> result = solution.twoSum(input, target);

    std::sort(result.begin(), result.end());

    EXPECT_EQ(expected.first, result[0]);
    EXPECT_EQ(expected.second, result[1]);
}

auto values = ::testing::Values(
                std::make_tuple<std::vector<int>, int, std::pair<int, int>>({2,7,11,15}, 9, std::make_pair(0,1)),
                std::make_tuple<std::vector<int>, int, std::pair<int, int>>({3,2,4}, 6, std::make_pair(1,2)),
                std::make_tuple<std::vector<int>, int, std::pair<int, int>>({3,3}, 6, std::make_pair(0,1))
                );

INSTANTIATE_TEST_CASE_P(
        TwoSumTest1,
        TwoSumTestFast,
        values
        );

INSTANTIATE_TEST_CASE_P(
        TwoSumTest2,
        TwoSumTestNoStorage,
        values
        );
#include <gtest/gtest.h>

#include <algorithm>
#include <tuple>
#include <vector>

#include "solution.hpp"

class FrequencyTest :public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {
protected:
    Solution solution;
};

TEST_P(FrequencyTest, CheckSolution) {
    const std::vector<int> input = std::get<0>(GetParam());
    int k = std::get<1>(GetParam());
    const std::vector<int> expected = std::get<2>(GetParam());

    std::vector<int> actual = solution.topKFrequent(input, k);

    std::sort(actual.begin(), actual.end());

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
        FrequencyTests,
        FrequencyTest,
        ::testing::Values(
                std::make_tuple<std::vector<int>, int, std::vector<int>>({1}, 1, {1}),
                std::make_tuple<std::vector<int>, int, std::vector<int>>({1, 1}, 1, {1}),
                std::make_tuple<std::vector<int>, int, std::vector<int>>({1, 1, 2}, 1, {1}),
                std::make_tuple<std::vector<int>, int, std::vector<int>>({1, 1, 2}, 2, {1, 2})
                )
        );
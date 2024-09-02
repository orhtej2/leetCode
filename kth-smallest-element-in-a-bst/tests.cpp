#include <gtest/gtest.h>

#include <tuple>
#include <vector>

#include "solution.hpp"

class KthSmallestBstTest :public ::testing::TestWithParam<std::tuple<std::vector<int>, int, int>> {
protected:
    Solution solution;
};

TEST_P(KthSmallestBstTest, CheckSolution) {
    std::vector<int> input = std::get<0>(GetParam());
    int k = std::get<1>(GetParam());
    int expected = std::get<2>(GetParam());

    auto tn = make_tree(input);

    int actual = solution.kthSmallest(tn.get(), k);

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
        KthSmallestBstTests,
        KthSmallestBstTest,
        ::testing::Values(
                std::make_tuple<std::vector<int>, int, int>({1}, 1, 1),
                std::make_tuple<std::vector<int>, int, int>({2,1}, 1, 1),
                std::make_tuple<std::vector<int>, int, int>({2,1}, 2, 2),
                std::make_tuple<std::vector<int>, int, int>({2,1,3,0,0,0,7}, 1, 1),
                std::make_tuple<std::vector<int>, int, int>({2,1,3,0,0,0,7}, 4, 7)
                )
        );
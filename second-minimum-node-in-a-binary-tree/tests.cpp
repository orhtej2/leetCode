#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "solution.hpp"
#include "solution_recursive.hpp"

template<typename S>
class KthSmallestBstTest :public ::testing::TestWithParam<std::pair<std::vector<int>, int>> {
protected:
    S solution;
};

typedef KthSmallestBstTest<Solution> KthSmallestBstTestNoRecursion;
typedef KthSmallestBstTest<SolutionRecursive> KthSmallestBstTestRecursive;

TEST_P(KthSmallestBstTestNoRecursion, CheckSolution) {
    std::vector<int> input = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());

    TreeNode* tn = make_tree(input);

    int actual = solution.findSecondMinimumValue(tn);

    delete_tree(tn);

    EXPECT_EQ(expected, actual);
}

TEST_P(KthSmallestBstTestRecursive, CheckSolution) {
    std::vector<int> input = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());

    TreeNode* tn = make_tree(input);

    int actual = solution.findSecondMinimumValue(tn);

    delete_tree(tn);

    EXPECT_EQ(expected, actual);
}

auto values = ::testing::Values(
                std::make_pair<std::vector<int>, int>({1}, -1),
                std::make_pair<std::vector<int>, int>({1, 1, 2}, 2),
                std::make_pair<std::vector<int>, int>({1,2,1}, 2),
                std::make_pair<std::vector<int>, int>({2,2,2}, -1),
                std::make_pair<std::vector<int>, int>({1,1,1,1,2,3,1}, 2),
                std::make_pair<std::vector<int>, int>({1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1}, 2)
                );

INSTANTIATE_TEST_SUITE_P(
        KthSmallestBstTestRecursives,
        KthSmallestBstTestRecursive,
        values
        );

INSTANTIATE_TEST_SUITE_P(
        KthSmallestBstTestNoRecursions,
        KthSmallestBstTestNoRecursion,
        values
        );
#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "solution.hpp"

typedef std::vector<int> ll;

class AddTwoNumbersTest :public ::testing::TestWithParam<std::tuple<ll, ll, ll>> {
protected:
    Solution solution;
};

TEST_P(AddTwoNumbersTest, CheckSolution) {
    const ll left = std::get<0>(GetParam());
    const ll right = std::get<1>(GetParam());
    const ll expected = std::get<2>(GetParam());

    ListNode* input1 = vector_to_list(left);
    ListNode* input2 = vector_to_list(right);

    ListNode* actual = solution.addTwoNumbers(input1, input2);
    delete_list(input1);
    delete_list(input2);

    ListNode* it = actual;
    for (auto i = expected.crbegin(); i != expected.crend(); ++i)
    {
        EXPECT_NE(nullptr, it);
        EXPECT_EQ(*i, it->val);
        it = it->next;
    }

    delete_list(actual);
}

INSTANTIATE_TEST_SUITE_P(
        AddTwoNumbersTests,
        AddTwoNumbersTest,
        ::testing::Values(
                std::tuple<ll, ll, ll>({1, 1}, {1, 1}, {2, 2}),
                std::tuple<ll, ll, ll>({1}, {1, 1}, {1, 2}),
                std::tuple<ll, ll, ll>({1, 1}, {1}, {1, 2}),
                std::tuple<ll, ll, ll>({9}, {1}, {1, 0})
                )
        );
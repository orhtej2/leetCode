#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "solution.hpp"

typedef std::vector<int> ll;
typedef ll::size_type ll_size_type;

class KthLargestInArrayTest :public ::testing::TestWithParam<std::tuple<ll, ll_size_type, int>> {
};

TEST_P(KthLargestInArrayTest, CheckSolution) {
  auto param = GetParam();
  const ll input = std::get<0>(param);
  const ll_size_type k = std::get<1>(param);
  const int expected = std::get<2>(param);

  Solution solution;

  EXPECT_EQ(expected, solution.findKthLargest(input, k));
}

INSTANTIATE_TEST_SUITE_P(
  KthLargestInArrayTests,
  KthLargestInArrayTest,
        ::testing::Values(
          std::tuple<ll, ll_size_type, int>({ 1, 2, 3 }, 3, 1),
          std::tuple<ll, ll_size_type, int>({ 3, 1 }, 1, 3)
        )
        );
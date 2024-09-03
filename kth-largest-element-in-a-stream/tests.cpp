#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "solution.hpp"

typedef std::vector<int> ll;
typedef ll::size_type ll_size_type;

class KthLargestTest :public ::testing::TestWithParam<std::tuple<int, ll, ll, ll>> {
};

TEST_P(KthLargestTest, CheckSolution) {
  auto param = GetParam();
  int k = std::get<0>(param);
    const ll initial = std::get<1>(param);
    const ll additional = std::get<2>(param);
    const ll expected = std::get<3>(param);

    KthLargest solution(k, initial);

    int result = 0;
    EXPECT_EQ(additional.size(), expected.size());

    for (ll_size_type i = 0; i < additional.size(); ++i) {
      EXPECT_EQ(expected[i], solution.add(additional[i]));
    }
}

INSTANTIATE_TEST_SUITE_P(
  KthLargestTests,
  KthLargestTest,
        ::testing::Values(
          std::tuple<int, ll, ll, ll>(1, { 1, 2, 3 }, { 1, 2, 3 }, { 3, 3, 3 }),
          std::tuple<int, ll, ll, ll>(1, { 2 }, { 3, 1 }, { 3, 3 }),
          std::tuple<int, ll, ll, ll>(2, { 2, 2, 2, 2 }, { 2, 3, 2 }, { 2, 2 , 2 }),
          std::tuple<int, ll, ll, ll>(3, { 4, 5, 8, 2 }, { 3, 5, 10, 9, 4 }, { 4, 5, 5, 8, 8 })
        )
        );
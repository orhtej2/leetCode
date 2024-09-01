#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "solution.hpp"

typedef std::vector<int> ll;
typedef std::vector<ll> lll;
typedef ll::size_type ll_size_type;

class Convert1dTo2dArrayTest :public ::testing::TestWithParam<std::tuple<ll, ll_size_type, ll_size_type, lll>> {
protected:
    Solution solution;
};

TEST_P(Convert1dTo2dArrayTest, CheckSolution) {
    const ll input = std::get<0>(GetParam());
    const ll_size_type m = std::get<1>(GetParam());
    const ll_size_type n = std::get<2>(GetParam());
    const lll expected = std::get<3>(GetParam());

    auto actual = solution.construct2DArray(input, m, n);

    EXPECT_EQ(expected.size(), actual.size());
    for (ll_size_type i = 0; i < expected.size(); ++i) {
      const auto& row = actual[i];
      const auto& expected_row = expected[i];
      EXPECT_EQ(expected_row.size(), row.size());
      for (ll_size_type j = 0; j < expected_row.size(); ++j) {
        EXPECT_EQ(expected_row[j], row[j]);
      }
    }
}

INSTANTIATE_TEST_SUITE_P(
  Convert1dTo2dArrayTests,
  Convert1dTo2dArrayTest,
        ::testing::Values(
          std::tuple<ll, ll_size_type, ll_size_type, lll>({1, 2, 3}, 1, 3, {{1, 2, 3}}),
          std::tuple<ll, ll_size_type, ll_size_type, lll>({ 1, 2, 3 }, 3, 1, { {1}, {2}, {3} }),
          std::tuple<ll, ll_size_type, ll_size_type, lll>({ 1, 2, 3, 4, 5, 6 }, 3, 2, { {1, 2}, {3, 4}, {5, 6} }),
          std::tuple<ll, ll_size_type, ll_size_type, lll>({ 1 }, 3, 2, { }),
          std::tuple<ll, ll_size_type, ll_size_type, lll>({ 1, 2, 3 }, 1, 2, { })
        )
        );
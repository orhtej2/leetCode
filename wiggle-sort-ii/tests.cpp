#include <algorithm>
#include <utility>
#include <vector>

#include "print_vector.hpp"

#include <gtest/gtest.h>

#include "solution.hpp"

typedef std::vector<int> ll;
typedef ll::size_type ll_size_type;

class KthLargestInArrayTest :public ::testing::TestWithParam<std::tuple<ll>> {
};

void check(const ll& v) {
  for (ll_size_type i = 1; i < v.size(); i += 2) {
    ASSERT_LT(v[i - 1], v[i]) << v;
    if (i < v.size() - 1) {
      ASSERT_LT(v[i + 1], v[i]) << v;
    }
  }
}

TEST_P(KthLargestInArrayTest, CheckSolution) {
  auto param = GetParam();
  ll input = std::get<0>(param);

  Solution solution;
  solution.wiggleSort(input);

  check(input);

  for (int i = 0; i < 20; ++i) {
    std::random_shuffle(input.begin(), input.end());
    solution.wiggleSort(input);

    check(input);
  }
}

INSTANTIATE_TEST_SUITE_P(
  KthLargestInArrayTests,
  KthLargestInArrayTest,
  ::testing::Values(
    std::make_tuple<ll>({ 1, 2, 3 }),
    std::make_tuple<ll>({ 3, 1 }),
    std::make_tuple<ll>({ 1 }),
    std::make_tuple<ll>({ 1, 5, 1, 1, 6, 4 }),
    std::make_tuple<ll>({ 1, 3, 2, 2, 3, 1 })
  )
);
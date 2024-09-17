#pragma once

#include <algorithm>
#include <vector>
#include <queue>

class Solution {
public:
  void wiggleSort(std::vector<int>& nums) {
    auto len = std::distance(std::begin(nums), std::end(nums));
    auto mid_it = std::begin(nums);
    std::advance(mid_it, len / 2);
    std::nth_element(std::begin(nums), mid_it, std::end(nums));
    auto mid = *mid_it;

    #define GET(X)  nums[(1 + 2*X) % (len|1)]

    size_t i = 0, j = 0, k = len - 1;
    while (j <= k) {
      if (GET(j) > mid) {
        std::swap(GET(i), GET(j));
        i++;
        j++;
      } else if (GET(j) < mid) {
        std::swap(GET(j), GET(k));
        k--;
      } else {
        j++;
      }
    }
  }
};
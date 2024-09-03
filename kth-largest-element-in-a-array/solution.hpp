#pragma once

#include <vector>
#include <queue>

class Solution {
public:
  int findKthLargest(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (auto n : nums) {
      q.push(n);
      if (q.size() > static_cast<size_t>(k)) {
        q.pop();
      }
    }

    return q.top();
  }
};
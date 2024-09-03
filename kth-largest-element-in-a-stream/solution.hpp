#pragma once

#include <cassert>

#include <algorithm>
#include <vector>
#include <queue>

class KthLargest {
  std::priority_queue<int, std::vector<int>, std::greater<int>> scores;
  const int k;
public:
  KthLargest(int k, const std::vector<int>& nums) : k(k) {
    assert(k > 0);
    for (auto score : nums) {
      add(score);
    }
  }

  int add(int val) {
    scores.push(val);
    if (scores.size() > static_cast<size_t>(k))
      scores.pop();

    return scores.top();
  }
};
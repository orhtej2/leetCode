#pragma once

#include <cassert>

#include <iterator>
#include <vector>
#include <set>

class KthLargest {
  std::multiset<int, std::greater<int>> scores;
  const int k;
public:
  KthLargest(int k, const std::vector<int>& nums) : k(k) {
    assert(k > 0);
    for (auto score : nums) {
      add(score);
    }
  }

  int add(int val) {
    if (scores.size() < static_cast<size_t>(k)) {
      scores.insert(val);
    }
    else {
      auto it = scores.lower_bound(val);
      if (it != scores.end()) {
        scores.insert(val);
        scores.erase(std::prev(scores.end()));
      }
    }
    return *(scores.rbegin());
  }
};
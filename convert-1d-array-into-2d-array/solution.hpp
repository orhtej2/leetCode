#pragma once

#include <iterator>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> construct2DArray(const std::vector<int>& original, 
    std::vector<int>::size_type m, std::vector<int>::size_type n) {
    if (original.size() != (n * m))
      return {};

    std::vector<std::vector<int>> ret;
    ret.reserve(m);
    for (std::vector<int>::size_type i = 0; i < m; ++i) {
      auto i_begin = original.begin();
      std::advance(i_begin, i * n);
      auto i_end = original.begin();
      std::advance(i_end, (i + 1)* n);
      ret.emplace_back(std::vector<int>{ i_begin, i_end });
    }

    return ret;
  }
};
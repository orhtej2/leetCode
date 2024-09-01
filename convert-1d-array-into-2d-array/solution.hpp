#pragma once

#include <iterator>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> construct2DArray(const std::vector<int>& original, 
    std::vector<int>::size_type m, std::vector<int>::size_type n) {
    if (original.size() != (n * m))
      return {};

    std::vector<std::vector<int>> ret(m);
    for (std::vector<int>::size_type i = 0; i < m; ++i) {
      ret[i].reserve(n);
      auto i_begin = original.begin();
      std::advance(i_begin, i * n);
      auto i_end = original.begin();
      std::advance(i_end, (i + 1)* n);
      std::copy(i_begin, i_end, std::back_inserter(ret[i]));
    }

    return ret;
  }
};
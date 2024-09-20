#pragma once

#include <algorithm>
#include <cstring>
#include <string>

class Solution {
public:
  std::string largestPalindromic(const std::string& s) {
    int counts[10];
    std::memset(counts, 0, sizeof(int) * 10);
    for (auto c : s) {
      counts[c - '0']++;
    }

    std::string result;
    bool nonzero = false;
    for (int i = 9; i > 0 || (i == 0 && nonzero); --i) {
      while (counts[i] > 1) {
        result += ('0' + i);
        counts[i] -= 2;
        nonzero = true;
      }
    }
    std::string mid;
    for (int i = 9; i >= 0; --i) {
      if (counts[i] != 0) {
        mid = '0' + i;
        break;
      }
    }

    result += mid + std::string(result.rbegin(), result.rend());
    return result;
  }
};
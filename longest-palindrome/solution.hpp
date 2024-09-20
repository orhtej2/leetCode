#pragma once

#include <string>
#include <unordered_map>

class Solution {
public:
  int longestPalindrome(const std::string& s) {
    std::unordered_map<char, int> chars;
    for (auto c : s) {
      chars[c]++;
    }

    int result = 0;
    bool odd = false;
    for (auto it : chars) {
      result += (it.second & ~1);
      if (!odd && (it.second & 1)) {
        result++;
        odd = true;
      }
    }

    return result;
  }
};
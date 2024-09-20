#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestPalindrome(const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> known;
    std::unordered_set<std::string> same;
    int result = 0;
    bool odd = false;
    for (auto c : words) {
      auto it = known.find(c);
      if (it != known.end()) {
        result += 4;
        it->second--;
        if (it->second == 0) {
          known.erase(it);
          same.erase(c);
        }
      }
      else {
        std::string reversed(c.rbegin(), c.rend());
        known[reversed]++;
        if (c[0] == c[1]) {
          same.insert(c);
        }
      }
    }

    if (!same.empty()) {
      result += 2;
    }

    return result;
  }
};
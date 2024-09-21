#pragma once

#include <string>
#include <vector>

class Solution {
public:
  std::vector<long long> kthPalindrome(const std::vector<int>& queries, int intLength) {
    std::vector<long long> result(queries.size(), 0);

    bool odd = intLength % 2 == 1;
    for (size_t i = 0; i < queries.size(); ++i) {
      result[i] = getNth(queries[i], odd, intLength);
    }

    return result;
  }

  long long getNth(int n, bool odd, int k) const {
    int multiplier = getMultiplier((k - 1) / 2);
    if (n > multiplier * 9) {
      return -1;
    }

    int n2 = multiplier + n - 1;

    int mid = -1;
    if (odd) {
      mid = n2 % 10;
      n2 = n2 / 10;
    }

    return getNumber(n2, mid, k/2);
  }

  int reversed(int input) const {
    int result = 0;
    while (input > 0) {
      result *= 10;
      result += (input % 10);
      input /= 10;
    }

    return result;
  }
public:
  long long getNumber(int input, int mid, int k) const {
    long long result = input;
    int multiplier = getMultiplier(k);

    return (mid >= 0 ? (result * 10 + mid) : result) * multiplier + reversed(input);
  }

  int getMultiplier(int k) const {
    int multiplier = 1;
    for (int i = 0; i < k; ++i) {
      multiplier *= 10;
    }

    return multiplier;
  }
};
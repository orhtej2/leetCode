#pragma once

#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> topKFrequent(const std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> frequencies;
        for (int i : nums)
        {
            frequencies[i]++;
        }
        std::vector<std::pair<int, int>> intermediate(frequencies.begin(), frequencies.end());
        std::sort(intermediate.begin(), intermediate.end(), [](const auto &left, const auto &right)
                  { return left.second > right.second; });

        std::vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            result.push_back(intermediate[i].first);
        }

        return result;
    }
};
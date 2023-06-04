#pragma once

#include <vector>
#include <unordered_map>

class SolutionFast {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> pairs;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = pairs.find(target-nums[i]);
            if (it != pairs.end())
            {
                return { i, it->second };
            }
            pairs[nums[i]] = i;
        }

        return {};
    }
};
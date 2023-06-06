#pragma once

#include <vector>
#include <unordered_map>

class SolutionFast {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> pairs;
        for (std::vector<int>::size_type i = 0; i < nums.size(); ++i) {
            auto it = pairs.find(target-nums[i]);
            if (it != pairs.end())
            {
                // TODO don't use static_cast<> to avoid UB.
                return { static_cast<int>(i), it->second };
            }
            pairs[nums[i]] = i;
        }

        return {};
    }
};
#pragma once

#include <vector>

class SolutionNoStorage {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        
        for (std::vector<int>::size_type i = 1; i < nums.size(); ++i)
        {
        
            for (std::vector<int>::size_type j = 0; j < i; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(j);
                    result.push_back(i);
                    
                    return result;
                }
            }
        }
        
        return result;
    }
};
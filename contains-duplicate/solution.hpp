#pragma once

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(const std::vector<int>& nums) 
    {
        std::unordered_set<int> seen;
        for (int i : nums)
        {
            if (seen.find(i) != seen.end())
                return true;
            seen.insert(i);
        }
        return false;
    }
};
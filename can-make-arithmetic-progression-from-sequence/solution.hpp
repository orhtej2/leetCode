#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) 
    {
        std::sort(arr.begin(), arr.end());
        const int target = arr[0] - arr[1];
        for (std::vector<int>::size_type i = 2; i < arr.size(); ++i)
        {
            if (arr[i-1] - arr[i] != target)
                return false;
        }
        return true;
    }
};
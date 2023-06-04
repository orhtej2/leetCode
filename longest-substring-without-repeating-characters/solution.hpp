#pragma once

#include <string>
#include <unordered_map>

typedef std::string::size_type size_t;

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) 
    {
        std::unordered_map<char, size_t> last;
        int result = 0;
        int start_idx = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            const auto previous = last.find(s[i]);
            if (previous != last.end())
            {
                const int candidate = i - start_idx;
                start_idx = previous->second + 1;
                if (candidate > result)
                    result = candidate;
                auto iterator = last.begin();
                while (iterator != last.end())
                {
                    if (iterator->second < start_idx)
                        iterator = last.erase(iterator);
                    else
                        iterator++;
                }
            }
            last[s[i]] = i;
        }

        const int candidate = s.length() - start_idx;
        if (candidate > result)
            result = candidate;

        return result;
    }
};
#include <iostream>
#include <string>

#include "solution.hpp"

int main()
{
    const std::string input("ohomm");
    Solution s;
    std::cout << "\"" << input << "\": " << s.lengthOfLongestSubstring(input) << std::endl;

    return 1;
}
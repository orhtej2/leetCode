#include <iostream>
#include <string>

#include "solution.hpp"

int main()
{
    const std::string input = "aab";
    Solution s;
    std::cout << "\"" << input << "\": " << s.longestPalindrome(input) << std::endl;

    return 0;
}
#include <iostream>
#include <string>

#include "solution.hpp"

int main()
{
    const std::string input = "112";
    Solution s;
    std::cout << "\"" << input << "\": " << s.largestPalindromic(input) << std::endl;

    return 0;
}
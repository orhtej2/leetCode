#include <iostream>
#include <string>

#include "solution.hpp"

int main()
{
    const std::string input("XCXLV");
    Solution s;
    std::cout << "\"" << input << "\": " << s.romanToInt(input) << std::endl;

    return 1;
}
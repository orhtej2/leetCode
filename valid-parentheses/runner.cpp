#include <iostream>
#include <string>

#include "solution.hpp"

int main()
{
    const std::string input("[]");
    Solution s;
    std::cout << "\"" << input << "\": " << (s.isValid(input) ? "true" : "false") << std::endl;

    return 1;
}
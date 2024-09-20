#include <iostream>
#include <string>
#include <vector>

#include "print_vector.hpp"

#include "solution.hpp"

int main()
{
  const std::vector<std::string> input = { "aa", "bb", "ab", "bc", "bb"};
    Solution s;
    std::cout << input << ": " << s.longestPalindrome(input) << std::endl;

    return 0;
}
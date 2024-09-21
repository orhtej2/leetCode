#include <iostream>
#include <string>

#include "print_vector.hpp"

#include "solution.hpp"


int main()
{
  const std::vector<int> input = { 1, 5 };
  const int k = 2;
  Solution s;
  std::cout << "\"" << input << "\": " << s.kthPalindrome(input, k) << std::endl;

  return 0;
}
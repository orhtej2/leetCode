#include <iostream>
#include <vector>

#include "print_vector.hpp"

#include "solution.hpp"

int main()
{
  Solution s;
  std::vector<int> input = { 1, 2, 3, 4 };
  std::cout << input << std::endl;
  s.wiggleSort(input);
  std::cout << input << std::endl;
  return 0;
}
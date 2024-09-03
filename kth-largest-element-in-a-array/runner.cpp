#include <iostream>
#include <vector>

#include "print_vector.hpp"

#include "solution.hpp"

int main()
{
  Solution s;
  std::cout << s.findKthLargest({ 1, 2, 3 }, 3);
  return 0;
}
#include <iostream>
#include <vector>

#include "print_vector.hpp"

#include "solution.hpp"

int main()
{
    std::vector<int> input = {1,2,3,1};
    Solution s;
    std::cout << "\"" << input << "\": " << (s.canMakeArithmeticProgression(input) ? "true" : "false") << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

#include "print_vector.hpp"

#include "solution.hpp"

int main()
{
    const std::vector<int> input = {1,2,3,1};
    Solution s;
    std::cout << "\"" << input << "\": " << (s.containsDuplicate(input) ? "true" : "false") << std::endl;

    return 1;
}
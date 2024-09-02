#include <vector>
#include <iostream>

#include "print_vector.hpp"

#include "solution1.hpp"
#include "solution2.hpp"

int main()
{
    SolutionFast s1;
    SolutionNoStorage s2;

    std::vector<int> input = {0, 1, 5, 7};
    std::cout << input << std::endl;

    std::cout << s1.twoSum(input, 12) << std::endl;
    std::cout << s2.twoSum(input, 12) << std::endl;

    return 0;
}

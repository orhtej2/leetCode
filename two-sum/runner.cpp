#include <vector>
#include <iostream>

#include "solution1.hpp"
#include "solution2.hpp"

void print(const std::vector<int>&v)
{
    std::cout << "[";
    bool first = true;
    for (const int i : v)
    {
        if (!first)
            std::cout<<",";
        std::cout<<i;
        first = false;
    }

    std::cout << "]" << std::endl;
}

int main()
{
    SolutionFast s1;
    SolutionNoStorage s2;

    std::vector<int> input = {0, 1, 5, 7};
    print(input);

    print(s1.twoSum(input, 12));
    print(s2.twoSum(input, 12));

    return 0;
}

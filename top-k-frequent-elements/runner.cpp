#include <iostream>
#include <vector>

#include "print_vector.hpp"

#include "solution.hpp"

int main()
{
    const std::vector<int> input = {1};
    const int k = 1;
    Solution s;
    std::cout << input << ": " << s.topKFrequent(input, k) << std::endl;

    return 1;
}
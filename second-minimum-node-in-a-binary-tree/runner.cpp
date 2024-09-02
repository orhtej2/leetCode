#include <iostream>
#include <vector>

#include "solution.hpp"

int main()
{
    std::vector<int> input = {1,1,1,1,2,3,1};
    auto tn = make_tree(input);
    Solution s;

    std::cout << tn << std::endl << std::endl << s.findSecondMinimumValue(tn.get()) << std::endl;

    return 0;
}
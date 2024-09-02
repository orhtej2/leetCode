#include <iostream>
#include <vector>

#include "linked_list.hpp"
#include "solution.hpp"

int main()
{
    auto input1 = int_to_list(92345);
    auto input2 = int_to_list(11111);

    Solution s;
    auto result = s.addTwoNumbers(input1.get(), input2.get());
    std::cout << input1 << " + " << input2 << " = " << result << std::endl;

    return 0;
}
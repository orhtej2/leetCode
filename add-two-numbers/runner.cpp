#include <iostream>
#include <vector>

#include "linked_list.hpp"
#include "solution.hpp"

int main()
{
    ListNode* input1 = int_to_list(92345);
    ListNode* input2 = int_to_list(11111);

    Solution s;
    ListNode* result = s.addTwoNumbers(input1, input2);
    std::cout <<  input1 << " + " << input2 << " = " << result << std::endl;

    delete_list(input1);
    delete_list(input2);
    delete_list(result);

    return 0;
}
#include <iostream>
#include <vector>

#include "solution.hpp"

int main()
{
    std::vector<int> input = {1,1,1,1,2,3,1};
    TreeNode* tn = make_tree(input);
    Solution s;

    std::cout << tn << std::endl << std::endl << s.findSecondMinimumValue(tn) << std::endl;

    delete_tree(tn);

    return 0;
}
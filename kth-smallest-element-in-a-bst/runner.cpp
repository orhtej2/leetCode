#include <iostream>
#include <vector>

#include "solution.hpp"

int main()
{
    std::vector<int> input = {2,1,3,0,0,0,5};
    TreeNode* tn = make_tree(input);
    Solution s;

    std::cout << tn << std::endl << std::endl << s.kthSmallest(tn, 4) << std::endl;

    delete_tree(tn);

    return 0;
}
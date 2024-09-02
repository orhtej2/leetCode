#pragma once

#include <utility>
#include "tree.hpp"

class SolutionRecursive {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr || root->left == nullptr)
            return -1;
        
        int candidate = -1;
        if (root->left->val != root->right->val)
            candidate = std::max(root->left->val, root->right->val);
        
        int left = findSecondMinimumValue(root->left.get());
        int right = findSecondMinimumValue(root->right.get());

        if (left != -1)
            candidate = candidate != -1 ? std::min(left, candidate) : left;

        if (right != -1)
            candidate = candidate != -1 ? std::min(right, candidate) : right;
        
        return candidate;
    }
};
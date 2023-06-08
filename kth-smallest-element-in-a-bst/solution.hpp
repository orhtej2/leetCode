#pragma once

#include <cassert>
#include <stack>
#include <vector>

#include "tree.hpp"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int visited = 0;
        std::stack<TreeNode*> q;
        while (true)
        {
            while (root != nullptr)
            {
                q.push(root);
                root = root->left;
            }
            if (q.empty())
            {
                assert(false);
            }
            root = q.top();
            q.pop();
            visited++;
            if (visited == k)
                return root->val;
            root = root->right;
        }
    }
};
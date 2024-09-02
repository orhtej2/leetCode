#pragma once

#include <queue>
#include <utility>

#include "tree.hpp"

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int candidate = -1;
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (root->left != nullptr)
            {
                if (root->left->val != root->right->val)
                {
                    int bigger = std::max(root->left->val, root->right->val);
                    candidate = candidate == -1 ? bigger : std::min(bigger, candidate);
                }
                if (candidate == -1 || root->left->val <= candidate)
                    q.push(root->left.get());
                if (candidate == -1 || root->right->val <= candidate)
                    q.push(root->right.get());
            }
        }

        return candidate;
    }
};
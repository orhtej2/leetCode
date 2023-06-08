#pragma once

#include <deque>
#include <ostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* make_tree(const std::vector<int>& values)
{
    if (values.empty())
        return nullptr;
    TreeNode* result = new TreeNode(values[0]);
    std::deque<TreeNode**> nodes;
    nodes.push_back(&(result->left));
    nodes.push_back(&(result->right));

    for (std::vector<int>::size_type i = 1; i < values.size(); ++i)
    {
        TreeNode** current = nodes.front();
        nodes.pop_front();

        if (values[i] != 0)
        {
            *current = new TreeNode(values[i]);
            nodes.push_back(&((*current)->left));
            nodes.push_back(&((*current)->right));
        }
    }

    return result;
}

void delete_tree(TreeNode *root)
{
    if (root == nullptr)
        return;
    
    delete_tree(root->left);
    delete_tree(root->right);

    delete root;
}

void print_tree_at_level(std::ostream&os, const TreeNode* const tn, int level, bool sibling_null)
{
    if (sibling_null && tn == nullptr)
        return;
    for (int i = 0; i < level; ++i)
    {
        if (i != 0)
            os << "  ";
        os << "|";
    }
    if (level != 0)
        os << "->";
    if (tn == nullptr)
        os << "<null>" << std::endl;
    else
    {
        os << tn->val << std::endl;
        print_tree_at_level(os, tn->left, level + 1, tn->right == nullptr);
        print_tree_at_level(os, tn->right, level + 1, tn->left == nullptr);
    }
}

std::ostream& operator<<(std::ostream& os, const TreeNode* const tn)
{
    print_tree_at_level(os, tn, 0, false);
    return os;
}
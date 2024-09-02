#pragma once

#include <deque>
#include <memory>
#include <ostream>
#include <vector>

struct TreeNode
{
    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
    TreeNode() : val(0) {}
    TreeNode(int x) : val(x) {}
    TreeNode(int x, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right) 
      : val(x), left(std::move(left)), right(std::move(right)) {}
};

std::unique_ptr<TreeNode> make_tree(const std::vector<int>& values)
{
    if (values.empty())
        return nullptr;
    auto result = std::make_unique<TreeNode>(values[0]);
    std::deque<std::unique_ptr<TreeNode>*> nodes;
    nodes.push_back(&(result->left));
    nodes.push_back(&(result->right));

    for (std::vector<int>::size_type i = 1; i < values.size(); ++i)
    {
        auto current = nodes.front();
        nodes.pop_front();

        if (values[i] != 0)
        {
            *current = std::make_unique<TreeNode>(values[i]);
            nodes.push_back(&((*current)->left));
            nodes.push_back(&((*current)->right));
        }
    }

    return result;
}

void print_tree_at_level(std::ostream& os, const std::unique_ptr<TreeNode>& tn, int level, bool sibling_null)
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

std::ostream& operator<<(std::ostream& os, const std::unique_ptr<TreeNode>& tn)
{
    print_tree_at_level(os, tn, 0, false);
    return os;
}
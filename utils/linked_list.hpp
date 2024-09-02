#pragma once

#include <memory>
#include <ostream>
#include <vector>

typedef unsigned long long int_t;

struct ListNode
{
    int_t val;
    std::unique_ptr<ListNode> next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int_t x) : val(x), next(nullptr) {}
    ListNode(int_t x, std::unique_ptr<ListNode> next) : val(x), next(std::move(next)) {}
};

std::unique_ptr <ListNode> int_to_list(unsigned long long n)
{
    std::unique_ptr<ListNode> result = nullptr;
    std::unique_ptr<ListNode> current = nullptr;
    while (n > 0)
    {
        auto next = std::make_unique<ListNode>(static_cast<int_t>(n % 10));
        if (current != nullptr)
        {
            current->next = std::move(next);
        }
        else
        {
            result = std::move(next);
        }

        current = std::move(next);
        n /= 10;
    }

    return result;
}

std::unique_ptr<ListNode> vector_to_list(const std::vector<int> input)
{
    std::unique_ptr<ListNode> result;
    for (auto i : input)
    {
        result = std::make_unique<ListNode>(static_cast<int_t>(i), std::move(result));
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const std::unique_ptr<ListNode>& input)
{
    os << '[';
    bool first = true;
    ListNode* node = input.get();
    while (node != nullptr)
    {
        if (!first)
            os << ',';
        else
            first = false;

        os << node->val;
        node = node->next.get();
    }
    os << ']';

    return os;
}

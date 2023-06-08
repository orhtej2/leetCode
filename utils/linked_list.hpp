#pragma once

#include <ostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void delete_list(ListNode* head)
{
    while(head != nullptr)
    {
        auto tmp = head->next;
        delete head;
        head = tmp;
    }
}

ListNode* int_to_list(unsigned long long n)
{
    ListNode* result = nullptr;
    ListNode* current = nullptr;
    while (n > 0)
    {
        ListNode* next = new ListNode(n % 10);
        if (current != nullptr)
        {
            current->next = next;
        }
        else
        {
            result = next;
        }

        current = next;
        n /= 10;
    }

    return result;
}

ListNode* vector_to_list(const std::vector<int> input)
{
    ListNode* result = nullptr;
    for (int i : input)
    {
        result = new ListNode(i, result);
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const ListNode* node)
{
    os << '[';
    bool first = true;
    while (node != nullptr)
    {
        if (!first)
            os << ',';
        else
            first = false;

        os << node->val;
        node = node->next;
    }
    os << ']';

    return os;
}

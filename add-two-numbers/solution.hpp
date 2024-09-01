#pragma once

#include "linked_list.hpp"

class Solution
{
public:
    std::unique_ptr<ListNode> addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        std::unique_ptr<ListNode> result;
        ListNode* current = nullptr;
        bool carry = false;

        while (l1 != nullptr || l2 != nullptr)
        {
            const auto left = l1 != nullptr ? l1->val : 0;
            const auto right = l2 != nullptr ? l2->val : 0;

            const auto val = left + right + (carry ? 1 : 0);
            auto next = std::make_unique<ListNode>(val%10);
            if (current != nullptr)
            {
                current->next = std::move(next);
            }
            else
            {
                result = std::move(next);
                current = result.get();
            }


            carry = val/10 > 0;
            if (l1 != nullptr)
                l1 = l1->next.get();
            if (l2 != nullptr)
                l2 = l2->next.get();
        }

        if (carry)
            current->next = std::make_unique<ListNode>(1);

        return result;
    }
};
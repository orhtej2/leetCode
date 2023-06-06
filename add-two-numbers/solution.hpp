#pragma once

#include "linked_list.hpp"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* result = nullptr;
        ListNode* current = nullptr;
        bool carry = false;

        while (l1 != nullptr || l2 != nullptr)
        {
            const int left = l1 != nullptr ? l1->val : 0;
            const int right = l2 != nullptr ? l2->val : 0;

            const int val = left + right + (carry ? 1 : 0);
            ListNode* next = new ListNode(val%10);
            if (current != nullptr)
            {
                current->next = next;
            }
            else
            {
                result = next;
            }

            current = next;

            carry = val/10 > 0;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (carry)
            current->next = new ListNode(1);

        return result;
    }
};
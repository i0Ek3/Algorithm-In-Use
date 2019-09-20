#include <iostream>

class Solution {
public:
    ListNode* kth(ListNode* head, unsigned int k) {
        if (!head || !k) return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 1; i < k; ++i) {
            if (fast->next) fast = fast->next;
            else return nullptr;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* kth(ListNode* head, unsigned int k) {
        ListNode *fast = head, *slow = head;
        int i = 0;
        for (; slow != nullptr; ++i) {
            if (i >= k) fast = fast->next;
            slow = slow->next;
        }
        return i < k ? nullptr : fast;
    }
};

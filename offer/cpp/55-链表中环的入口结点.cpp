#include <iostream>

// 设置两个指针，一快一慢，快指针每次走两步，慢指针每次走一步。链表存在环，则两个指针相遇，此时只需要将其中一个指针置为链表的头部，另一个不变，两个指针这回每次都走一步，相遇的地方就是环的入口。


class Solution {
public:
    ListNode* entry(ListNode* head) {
        set<ListNode*> s;
        ListNode* node = head;
        while (node) {
            if (s.insert(node).second) node = node->next;
            else return node;
        }
        return node;
    }


    ListNode* entry(ListNode* head) {
        if (!head->next) return nullptr;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast) {
            slow->next = nullptr;
            slow = fast;
            fast = fast->next;
        }
        return slow;
    }



    ListNode* entry(ListNode* head) {
        if (!head || !head->next) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                if (fast == slow) return slow;
            }
        }
        return nullptr;
    }
};



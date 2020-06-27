#include <iostream>

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2) {
        ListNode *p1 = head1, *p2 = head2;
        while (p1 != p2) {
            p1 = (p1 == NULL ? pHead2 : p1->next);
            p2 = (p2 == NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};

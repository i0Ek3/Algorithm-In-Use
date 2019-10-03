class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* node = head;
        ListNode* pre = &dummy;

        while (node && node->next) {
            if (node->val == node->next->val) {
                int val = node->val;
                while (node && node->val == val) {
                    node = node->next;
                }
                pre->next = node;
            } else {
                pre = node;
                node = node->next;
            }
        }
        return dummy.next;
    }
};

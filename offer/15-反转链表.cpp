class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* cur = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = cur->next;
            cur = head;
            head = next;
        }
        return cur;
    }
};

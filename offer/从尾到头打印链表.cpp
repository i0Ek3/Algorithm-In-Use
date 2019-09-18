#include <iostream>
#include <vector>
using namespace std;

vector<int> tail(ListNode* head) {
    vector<int> res;
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    reverse(res.begin(), res.end());
    return res;
}


ListNode* tail(ListNode* head) {
    if (head) {
        if (head->next) {
            tail(head->next);
        }
        cout << head->next->val << endl;
    }
    return head;
         
}



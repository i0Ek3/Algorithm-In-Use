// Single List Operations
// ref https://segmentfault.com/a/1190000002490878
//

// 倒置
ListNode* reverse(ListNode *root) {
    ListNode *node = nullptr; // 定义一个空指针指向一个空节点
    while (root) {
        ListNode *next = root->next;
        root->next = node;
        node = root;
        root = next;
    }
    return node;
}

// 去重
ListNode* rmDup(ListNode *head) {
    if (head == nullptr) {
        return head;
    }
    for (ListNode *cur = head; cur->next; ) {
        if (cur->val == cur->next->val) { // 判断当前指针所指的值是否等于当前指针的下一指针所指的值
            ListNode *next = cur->next->next;
            delete cur->next;
            cur->next = next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

// 合并
// 这个问题本身非常简单，但想通过这个基本问题，引申出链表问题一个非常常见的技巧。即设立 dummy 节点，可以称为是傀儡节点，其作用在于让合成的新链表有一个着手点。这个节点的值可以随意，我们最终返回的，实际上是 dummy.next
ListNode* merge(ListNode *a, ListNode *b) {
    ListNode dummy(0); // 设立一个傀儡节点，这里指向0
    ListNode *tail = &dummy; // 指向dummy的tail
    while (a && b) {
        tail->next = a;
        tail = a;
        a = a->next;
        tail-next = b;
        tail = b;
        b = b->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

// 移动节点
void moveNode(ListNode **dest, ListNode **src) {
    ListNode *newNode = *src;
    *src = newNode->next;
    newNode->next = *dest;
    *dest = newNode;
}



// 顺序合并
// 顺序插入
// 排序
//

ps: 未完待续...

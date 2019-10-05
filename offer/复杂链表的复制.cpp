class Solution {


    /*
     *  答案改写自牛客@一阶小民
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
    */

public:
    RandmListNode* Clone(RandmListNode* head) {
        if (!head) return nullptr;
        RandmListNode* cur = head;

        // 1
        while (cur) {
            RandmListNode* node = new RandmListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            node = node->next;
        }

        cur = head;
        // 2
        while (cur) {
            RandmListNode* node = cur->next;
            if (cur->random)
                node->random = cur->random->next;
            cur = node->next;
        }

        // 3
        RandmListNode* clone = head->next;
        RandmListNode* tmp;
        cur = head;
        while (cur->next) {
            tmp = cur->next;
            cur->next = tmp->next;
            cur = tmp;
        }
        return clone;
    }
};

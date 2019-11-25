class Solution {
public:
    TreeNode* convert(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* pre = nullptr; // 用指向前一个节点的指针来维护链表
        h(root, pre);
        TreeNode* res = root;
        while (res->left) {
            res = res->left;
        }
        return res;
    } 

    void h(TreeNode* cur, TreeNode*& pre) {
        if (cur == nullptr) return;
        h(cur->left, pre);
        cur->left = pre;
        if (pre) pre->right = cur;
        pre = cur;
        h(cur->right, pre);
    }
};

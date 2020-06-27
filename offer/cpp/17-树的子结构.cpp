#include <iostream>

class Solution {
public:
    bool HasSubtree(TreeNode* t1, TreeNode* t2) {
        bool flag = false;
        if (t1 && t2) { // 两者存在才可以比较
            if (t1->val == t2->val) flag = helper(t1, t2);  // 如果二者有相同的根节点，则以这个根节点判断是否包含t2
            if (!flag) flag = HasSubtree(t1->left, t2); // 如果没找到，则去t1的左子树找t2
            if (!flag) flag = HasSubtree(t1->right, t2); // 如果还没有找到，则去t1的右子树找t2
        }
        return flag;
    }

    bool helper(TreeNode* t1, TreeNode* t2) {
        if (!t1) return false; // 如果t2还没有遍历完，但是t1已经结束，则不存在
        if (!t2) return true; // 如果t2遍历完在t1中对应的结点，则存在
        if (t1->val == t2->val) return true; // 如果都相等，则ok
        return helper(t1->left, t2->left) && helper(t1->right, t2->right); // 如果根节点都对应上了，则去左右子树分别匹配
    }
};


class Solution {
public:
    bool helper(TreeNode* root1, TreeNode* root2) {
        if (!root1) return false;
        if (!root2) return true;
        if (root1->val == root2->val) return sub(root1->left, root2->left) && sub(root1->right, root2->right);
        else return false;
    }
    bool sub(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return false;
        return helper(root1, root2) || helper(root1->left, root2) || hepler(root1->right, root2);
    }
};

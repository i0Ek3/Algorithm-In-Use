class Solution {
public:
    bool isSe(TreeNode* root) {
        if (root == nullptr) return true;
        return h(root->left, root->right);
    }
    
    bool h(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return true;
        if (left->val != right->val) return false;
        return left->val == right->val && h(left->left, right->right) && h(left->right, right->left)
    }
};

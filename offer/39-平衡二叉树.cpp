class Solution {
public:
    bool isBalance(TreeNode* root) {
        if (root == nullptr) return true;
        return abs(h(root->left)-h(root->right) <= 1 && isBalance(root->left) && isBalance(root->right));
    }

    int h(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(h(root->left), h(root->right));
    }
};

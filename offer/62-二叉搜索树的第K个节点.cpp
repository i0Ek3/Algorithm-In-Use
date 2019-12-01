class Solution {
public:
    int cnt = 0;
    TreeNode* kth(TreeNode* root, int k) {
        if (root != nullptr) {
            TreeNode* node = kth(root->left, k);
            if (node != nullptr) return node;
            cnt++;
            if (cnt == k) return root;
            node = kth(root->right, k);
            if (node != nullptr) return node;
        }
        return nullptr;
    }
};

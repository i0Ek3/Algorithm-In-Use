#include <iostream>

class Solution {
public:
    void mirror(TreeNode* root) {
        if (!root) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirror(root->left);
        mirror(root->right);
    }
};

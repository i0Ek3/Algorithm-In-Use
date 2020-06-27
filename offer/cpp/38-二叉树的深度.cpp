class Solution {
public:
    int TreeDepth(TreeNode* root) {
        return max(TreeDepth(root->left), TreeDepth(root->right))+1;
    }
};

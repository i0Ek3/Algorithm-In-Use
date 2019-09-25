class Solution {
public:
    int TreeDepth(TreeNode* root) {
        return max(TreeNode(root->left), TreeNode(root->right))+1;
    }
};

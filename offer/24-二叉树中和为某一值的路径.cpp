class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root, int t) {
        if (root) dfs(root, t);
        return res;
    }

private:
    vector<int> v;
    vector<vector<int>> res;

    void dfs(TreeNode* root, int t) {
        v.push_back(root->val);
        if (t - root->val == 0 && !root->left && !root->right) {
            res.push_back(v);
        } else {
            if (root->left) dfs(root->left, t - root->val);
            if (root->right) dfs(root->right, t - root->val);
        }
        v.pop_back();
    }
};

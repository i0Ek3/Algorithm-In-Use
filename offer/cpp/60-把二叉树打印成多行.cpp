class Solution {
public:
    vector<vector<int>> Print(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int l = 0, h = q.size();
            vector<int> v; // save nodes' val
            while (l++ < h) {
                TreeNode* t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(v);
        }
        return res;
    }
};

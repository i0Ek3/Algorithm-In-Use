class Solution {
public:
    vector<vector<int>> Print(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool yes = false;
        while (!q.empty()) {
            int l = 0, h = q.size();
            while (l++ < h) {
                TreeNode* t = q.front();
                q.pop();
                vector<int> v;
                v.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (yes) reverse(v.begin(), v.end());
            yes = !yes;
            res.push_back(v)
        }
        return res;
    }
};

class Solution {
public:
    char* Serialize(TreeNode* root) {
        v.clear();
        h1(root);
        int *res = new int[v.size()];
        for (unsigned int i = 0; i < v.size(); ++i) {
            res[i] = v[i];
        }
        return (char*)res;
    }

    TreeNode* Deserialize(char* str) {
        int *root = (int*)str;
        return h2(root);
    }

private:
    vector<int> v;
    void h1(TreeNode* root) {
        if (root == nullptr) {
            v.push_back('#'); 
        } else {
            v.push_back(root->val);
            h1(root->left);
            h1(root->right);
        }
    }

    TreeNode* h2(int* &root) {
        if (*root == '#') {
            ++root;
            return nullptr;
        }
        TreeNode* node = new TreeNode(*root);
        ++root;
        node->left = h2(root);
        node->right = h2(root);
        return node;
    }
};

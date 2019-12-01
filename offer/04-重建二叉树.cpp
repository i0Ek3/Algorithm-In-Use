#include <iostream>
#include <vector>
using namespace std;

vector<int> helper(vector<int> num, int l, int r) {
    return vector<int> (num.begin()+l, num.begin()+r);
}

TreeNode* refactor(<vector<int> pre, vector<int>> in) {
    if (pre.size() == 0 || in.size() == 0) return nullptr;
    TreeNode *root = new TreeNode(pre[0]);
    for (int i = 0; i < in.length(); ++i) {
        if (in[i] == pre[0]) {
            root->left = refactor(helper(pre, 1, i+1), helper(in, 0, i));
            root->right = refactor(helper(pre, i+1, pre.size()), helper(in, i+1, in.size()));
            break;
        } 
    }
    return root;
}



int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


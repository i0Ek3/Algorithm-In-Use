class Solution {
public:
    TreeNode* theNext(TreeNode* node) {
        if (node == nullptr) return nullptr;

        // 右子树存在，找当前节点的左子节点
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }

        // 右子树不存在，找到第一个当前节点是父节点的左孩子节点
        while (node->next) {
            if (node->next->left == node) {
                return node->next;
            }
            node = node->next;
        }
        return nullptr;
    }
};

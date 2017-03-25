class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool isValidBST(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!isValidBST(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return isValidBST(node->right, prev);
    }
};
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        _push(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto node = _stack.top();
        _stack.pop();
        _push(node->right);
        return node->val;
    }

    void _push(TreeNode* node){
        while(node != nullptr){
            _stack.push(node);
            node = node->left;
        }
    }
private:
    stack<TreeNode*> _stack;
};
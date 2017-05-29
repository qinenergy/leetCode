class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        while(root->left != nullptr){
            TreeLinkNode* node = root;
            while(node != nullptr){
                node->left->next = node->right;
                if(node->next != nullptr)
                    node->right->next = node->next->left;
                node = node->next;
            }
            root = root->left;
        }
    }
};

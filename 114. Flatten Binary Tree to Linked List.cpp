class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr != nullptr){
            TreeNode* left = curr->left;
            if(left != nullptr){
                if(curr->right != nullptr)
                    st.push(curr->right);
                curr->left = nullptr;
                curr->right = left;
                curr = left;
            }
            else{
                if(curr->right == nullptr){
                    if(st.empty())
                        return;
                    else{
                        TreeNode* next = st.top();
                        st.pop();
                        curr->right = next;
                        curr = next;
                    }
                }
                else    curr = curr->right;
            }
        }
    }

    // Solution 2. By modifying the right-most treenode of left subtree
    void flatten(TreeNode *root) {
        while(root){
            if(root->left == NULL)
                root = root->right;
            else {
                if(root->right){
                    TreeNode *l = root->left;
                    while(l->right) l = l->right;
                    l->right = root->right;
                }
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};

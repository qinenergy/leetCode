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
};

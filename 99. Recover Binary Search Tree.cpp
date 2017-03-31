class Solution2 {
public:
    void recoverTree(TreeNode* root) {
        // o(n) space
        vector<TreeNode*> v;
        inorder(root, v);
        int i = 0, j = v.size() - 1;
        while(i < v.size() - 1 && v[i + 1]->val > v[i]->val) ++i;
        while(j > i && v[j]->val > v[j - 1]->val) -- j;
        if(j <= i) return;
        swap(v[i]->val, v[j]->val);
    }
    void inorder(TreeNode* root, vector<TreeNode*>& v){
        if(root == nullptr) return;
        if(root->left)  inorder(root->left, v);
        v.push_back(root);
        if(root->right) inorder(root->right, v);
    }

    void recoverTreeMorris(TreeNode* root) {
        // morris traversal, o(1) space
        TreeNode* prev = nullptr, *curr = root, *last;
        vector<TreeNode*> wrong;
        while(curr != nullptr){
            if(curr->left == nullptr){
                if(last && last->val > curr->val){
                    wrong.push_back(last);
                    wrong.push_back(curr);
                }
                last = curr;
                curr = curr->right;
            }
            else{
                prev = curr->left;
                while(prev->right != nullptr && prev->right != curr)   prev = prev->next;
                if(prev->right == nullptr){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    if(last && last->val > curr->val){
                        wrong.push_back(last);
                        wrong.push_back(curr);
                    }
                    last = curr;
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        if(wrong.size() > 0)    swap(wrong.front()->val, wrong.back()->val);
    }
};
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
};
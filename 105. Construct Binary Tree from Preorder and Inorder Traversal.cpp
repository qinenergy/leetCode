class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size())   throw new runtime_error("invalid");
        int len = preorder.size();
        auto pre = preorder.data();
        auto in = inorder.data();
        return buildTree(pre, in, len);
    }
    TreeNode* buildTree(int* pre, int* in, int n){
        if(n == 0)  return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        int root_ind = 0, nleft;
        while(root_ind < n && in[root_ind] != pre[0])  ++root_ind;
        if(root_ind == n)   throw new runtime_error("invalid");
        nleft = root_ind;
        if(nleft > 0)
            root->left = buildTree(pre + 1, in, nleft);
        if(n - nleft - 1 > 0)
            root->right = buildTree(pre + nleft + 1, in + nleft + 1, n - nleft - 1);
        return root;
    }
};
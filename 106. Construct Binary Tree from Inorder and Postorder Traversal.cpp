class Solution2 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size() || inorder.size() == 0)
            return nullptr;
        int n = inorder.size();
        return buildTree(inorder, postorder, 0, n, 0, n);
    }
    TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder,
                        int in_start, int in_end, int post_start, int post_end){
        if(post_start >= post_end)  return nullptr;
        TreeNode* root = new TreeNode(postorder[post_end - 1]);
        int root_ind = in_start;
        while(root_ind < in_end && inorder[root_ind] != postorder[post_end - 1])
            ++root_ind;
        int nb_left = root_ind - in_start, nb_right = in_end - in_start - nb_left - 1;
        if(nb_left > 0){
            root->left = buildTree(inorder, postorder,
                in_start, root_ind,
                post_start, post_start + nb_left);
        }
        if(nb_right > 0){
            root->right = buildTree(inorder, postorder,
                root_ind + 1, in_end,
                post_start + nb_left, post_end - 1);
        }
        return root;
    }
};

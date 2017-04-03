class Solution2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> rst;
        vector<int> path;
        psum(rst, path, root, sum);
        return rst;
    }
    void psum(vector<vector<int>>& rst, vector<int>& path, TreeNode* root, int sum){
        if(root && sum == root->val && root->left == nullptr && root->right == nullptr)){
            path.push_back(root->val);
            rst.push_back(path);
            path.pop_back();
            return;
        }
        if(root){
            path.push_back(root->val);
            if(root->left)  psum(rst, path, root->left, sum - root->val);
            if(root->right) psum(rst, path, root->right, sum - root->val);
            path.pop_back();
        }
    }
};
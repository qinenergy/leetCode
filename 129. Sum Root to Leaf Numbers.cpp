class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        int sum = 0;
        sumToLeaf(root, 0, sum);
        return sum;
    }
    void sumToLeaf(TreeNode* root, int num, int& sum){
        num = root->val + num * 10;
        if(!root->left && !root->right) sum += num;
        if(root->left)  sumToLeaf(root->left, num, sum);
        if(root->right)  sumToLeaf(root->right, num, sum);
    }
};
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
    	return isValidBST(root, INT_MAX, INT_MIN);
    }
    bool isValidBST(TreeNode* root, int M, int m){
    	if(!root)	return true;
    	if(root->val >= M || root->val <= m)	return false;
    	if(!root->left){
    		if(!root->right)	return true;
    		return isValidBST(root->right, M, max(root->val, m));
    	}
    	if(!root->right){
    		if(!root->left)	return true;
    		return isValidBST(root->left, min(root->val, M), m);
    	}
    	return root->left->val < root->val &&
    		root->right->val > root->val &&
    		isValidBST(root->left, min(root->val, M), m) &&
    		isValidBST(root->right, M, max(root->val, m));
    }
};
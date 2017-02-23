struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->right) q.push(root->right);
            if(root->left) q.push(root->left);
        }
        return root->val;
    }
};

class Solution2 {
public:
	int findBottomLeftValue(TreeNode* root) {
		int layer = 0;
		TreeNode* leaf = dfs(root, layer);
		return leaf->val;
	}

	TreeNode* dfs(TreeNode* root, int& layer){
		int ll=layer + 1, lr=layer + 1;
		TreeNode* lLeaf(nullptr), *rLeaf(nullptr);
		if(root->left==nullptr && root->right==nullptr)	{
			++layer;
			return root;
		}
		if(root->left!=nullptr)	lLeaf = dfs(root->left, ll);
		if(root->right!=nullptr) rLeaf = dfs(root->right, lr);
		if(ll >= lr){
			layer = ll;
			return lLeaf;
		}
		else{
			layer = lr;
			return rLeaf;
		}
	}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:
	int findBottomLeftValue(TreeNode* root) {

	}

	TreeNode* dfs(TreeNode* root, int& layer){
		if(root==nullptr){
			layer = 0;
			return nullptr;
		}
		int ll=layer, lr=layer;
		TreeNode* lLeaf(nullptr), *rLeaf(nullptr);
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
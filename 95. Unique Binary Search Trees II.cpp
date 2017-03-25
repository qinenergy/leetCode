class Solution2 {
public:
    vector<TreeNode*> generateTrees(int n) {
   		return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int s, int e){
    	vector<TreeNode*> trees;
    	for(int i = s; i <= e; ++i){
    		auto left = i == s ? vector<TreeNode*>{nullptr}:generateTrees(s, i - 1);
    		auto right = i == e ? vector<TreeNode*>{nullptr}:generateTrees(i + 1, e);
    		for(auto& pleft : left){
    			for(auto& pright : right){
    				TreeNode* root = new TreeNode(i);
    				root->left = pleft;
    				root->right = pright;
    				trees.push_back(root);
    			}
    		}
    	}
    	return trees;
    }
};
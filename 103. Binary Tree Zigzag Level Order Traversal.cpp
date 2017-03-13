class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> rst;
    	if(root == nullptr)	return rst;
    	stack<TreeNode*> st1, st2;
    	st1.push(root);
    	bool toLeft = false;
    	while(1){
    	    rst.push_back({});
    		while(!st1.empty()){
    			auto node = st1.top();
    			st1.pop();
    			rst.back().push_back(node->val);
    			if(toLeft){
    				if(node->right != nullptr) st2.push(node->right);
	    			if(node->left != nullptr) st2.push(node->left);
    			}
	    		else{
	    			if(node->left != nullptr) st2.push(node->left);
	    			if(node->right != nullptr) st2.push(node->right);
	    		}
    		}
    		swap(st1, st2);
    		toLeft = !toLeft;
    		if(st1.empty() && st2.empty())	break;
    	}
    	return rst;
    }
};
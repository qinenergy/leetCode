class Solution2 {
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> rst;
		if (root == nullptr)	return rst;
		unordered_map<int, int> sumMap;
		int maxCnt = INT_MIN;
		int sum = sumUpNodes(root, sumMap);
		for(auto& v : sumMap){
			if(v.second > maxCnt){
				maxCnt = v.second;
				rst.clear();
				rst.push_back(v.first);
			}
			else if(v.second == maxCnt)
				rst.push_back(v.first);
		}
		return rst;
	}
	int sumUpNodes(TreeNode* root, unordered_map<int, int>& sumMap) {
		if (root == nullptr)	return 0;
		int sum = root->val + sumUpNodes(root->left, sumMap) + sumUpNodes(root->right, sumMap);
		++sumMap[sum];
		return sum;
	}
};
class Solution2 {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
		int cnt1(0), cnt2(0), max(INT_MIN);
		vector<int> rst;
		if (root == nullptr)	return rst;
		q.push(root);
		cnt1 = 1;
		while (!q.empty()) {
			max = INT_MIN;
			while (cnt1--) {
				auto node = q.front();
				q.pop();
				if (node->val > max)	 max = node->val;
				if (node->left != nullptr) {
					q.push(node->left);
					++cnt2;
				}
				if (node->right != nullptr) {
					q.push(node->right);
					++cnt2;
				}
			}
			rst.push_back(max);
			cnt1 = cnt2;
			cnt2 = 0;
		}
		return rst;
    }
};
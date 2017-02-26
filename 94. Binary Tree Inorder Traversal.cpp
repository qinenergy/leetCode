class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rst;
		TreeNode* curr = root, *prev = nullptr;
		while (curr != nullptr) {
			if (curr->left == nullptr) {
				rst.push_back(curr->val);
				curr = curr->right;
			}
			else {
				prev = curr->left;
				while (prev->right != curr && prev->right != nullptr)
					prev = prev->right;
				if (prev->right == nullptr) {
					prev->right = curr;
					curr = curr->left;
				}
				else {
					prev->right = nullptr;
					rst.push_back(curr->val);
					curr = curr->right;
				}
			}
		}
		return rst;
    }
};
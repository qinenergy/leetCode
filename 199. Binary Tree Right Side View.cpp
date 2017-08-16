class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rst;
        if(root == nullptr) return rst;
        queue<TreeNode*> q;
        int nCurr = 1, nNext = 0;
        q.push_back(root);
        while(!q.empty()){
            auto& node = q.front();
            q.pop_front();
            --nCurr;
            if(node->left != nullptr){
                q.push_back(node->left);
                ++nNext;
            }
            if(node->right != nullptr){
                q.push_back(node->right);
                ++nNext;
            }
            if(nCurr == 0){
                rst.push_back(node->val);
                nCurr = nNext;
                nNext = 0;
            }
        }
        return rst;
    }
};
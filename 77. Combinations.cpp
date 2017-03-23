class Solution2 {
public:
    vector<vector<int>> combine(int n, int k) {
    	if(n < k || n < 1)	return {};    
    	vector<vector<int>> rst;
    	vector<int> comb;
    	combine(rst, comb, 1, n, k);
    	return rst;
    }
    void combine(vector<vector<int>>& rst, vector<int>& comb, int start, int n, int k){
    	if(k == 0){
    		rst.push_back(comb);
    		return;
    	}
    	for(int i = start; i <= n - k + 1; ++i){
    		comb.push_back(i);
    		combine(rst, comb, i + 1, n, k - 1);
    		comb.pop_back();
    	}
    }
};
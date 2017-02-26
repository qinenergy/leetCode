class Solution2 {
public:
	void combine(vector<int>& comb, vector<vector<int>>& rst, int start, int k, int n) {
		if (9 - start < k || k <= 0 || k > 9)	return;
		if (k == 1) {
			if (start + 1 <= n && n <= 9) {
				comb.push_back(n);
				rst.push_back(comb);
				comb.pop_back();
			}
			return;
		}
		else {
			for (int i = start; i < min(n, 9); ++i) {
				comb.push_back(i + 1);
				combine(comb, rst, i + 1, k - 1, n - i - 1);
				comb.pop_back();
			}
		}
	}
	
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> rst;
		int max = (k*(19 - k)) >> 1;
		if (n < 1 || n > max || k <= 0 || k > 9)	return rst;
		vector<int> comb;
		combine(comb, rst, 0, k, n);
		return rst;
	}
};
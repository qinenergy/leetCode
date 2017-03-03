class Solution2 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> rst;
		vector<int> sol;
		combination(rst, sol, candidates, 0, candidates.size(), target);
		return rst;
	}
	void combination(vector<vector<int>>& rst, vector<int>& sol, vector<int>& vec, int start, int end, int target) {
		if (start == end || target < 0)	return;
		if (target == 0) {
			rst.push_back(sol);
			return;
		}
		int i;
		for (i = start; i < end && vec[i] <= target; ++i) {
			sol.push_back(vec[i]);
			combination(rst, sol, vec, i, end, target - vec[i]);
			sol.pop_back();
		}
	}
};
class Solution2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> rst;
		int len = candidates.size();
		if (len == 0)	return{};
		vector<int> sol;
		sort(candidates.begin(), candidates.end());
		combination(rst, sol, candidates, 0, len, target);
		return rst;
	}
	void combination(vector<vector<int>>& rst, vector<int>& sol, vector<int>& vec, int start, int end, int target) {
		if (target < 0)	return;
		if (target == 0) {
			rst.push_back(sol);
			return;
		}
		int i = start;
		while (i < end) {
			if (target - vec[i] < 0)	break;
			sol.push_back(vec[i]);
			combination(rst, sol, vec, i + 1, end, target - vec[i]);
			sol.pop_back();
			++i;
			while (i < end && vec[i] == vec[i - 1])	++i;
		}
	}
};
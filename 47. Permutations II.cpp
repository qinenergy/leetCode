class Solution2 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> rst;
		if (len <= 1)	return{ nums };
		permute(rst, nums, 0, len);
		return rst;
	}
	void permute(vector<vector<int>>& rst, vector<int>& nums, int start, int end){
		if (start == end) {
			rst.push_back(nums);
			return;
		}
		int i = start;
		map<int, int> m;
		while (i < end) {
			if (m.find(nums[i]) != m.end()) {
				++i;
				continue;
			}
			swap(nums[start], nums[i]);
			m.insert({ nums[start], 1 });
			permute(rst, nums, start + 1, end);
			swap(nums[start], nums[i]);
			++i;
		}
	}
};
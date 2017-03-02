class Solution2 {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		if(len < 2)	return;
		int i, j, min(INT_MAX);
		for(i = len - 2; i >= 0; --i)
			if(nums[i] < nums[i + 1])
				break;
		reverse(nums.begin() + i + 1, nums.end());
		if(i == -1)	return;
		auto it = upper_bound(begin(nums)+i+1, end(nums), nums[i]);
		swap(nums[i], *it);
	}
};
class Solution2 {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
		int len = nums.size();
		if(len <= 2) return {};
		vector<vector<int>> rst;	
		sort(nums.begin(), nums.end());
		int start = 0, mid = 1, end = len - 1, sum;
		for(int start = 0; start < len - 2;){
			mid = start + 1, end = len - 1;
			while(mid < end){
				sum = nums[start] + nums[mid] + nums[end];
				if(sum == 0){
					rst.push_back(vector<int>{nums[start], nums[mid], nums[end]});
					++mid;
					--end;
					while(mid < end && nums[mid] == nums[mid - 1]) ++mid;
					while(end > mid && nums[end] == nums[end + 1])	++end;
				}
				else if(sum < 0){
					++mid;
					while(mid < end && nums[mid] == nums[mid - 1])	++mid;	
				}
				else{
					--end;
					while(end > mid && nums[end] == nums[end + 1])	--end;
				}
			}
			++start;
			while(start < len - 2 && nums[start] == nums[start - 1])	++start;
		}
		return rst;
	}
};
class Solution2 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if(nums.size() == 0)	return { -1, -1 };
    	int lo = findLowerBound(nums, target);
    	int hi = findLowerBound(nums, target + 1) - 1;
    	if(lo >= nums.size() || nums[lo] != target)	return { -1, -1 };
    	return { lo, hi };
    }  
    int findLowerBound(vector<int>& nums, int target){
    	int lo = 0, hi = nums.size() - 1, mid;
    	while(lo <= hi){
    		mid = lo + (hi - lo) / 2;
    		if(nums[mid] < target)	lo = mid + 1;
    		else hi = mid - 1;
    	}
    	return lo;
    }
};
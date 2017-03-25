class Solution2 {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();    
    	int lo = 0, hi = len - 1, mid, real_mid;
    	while(lo < hi){
    		mid = lo + (hi - lo) / 2;
    		if(nums[mid] == target)	return true;
    		if(nums[mid] == nums[lo] && nums[mid] == nums[hi]) ++lo;
    		else if(nums[mid] > nums[hi])	lo = mid + 1;
    		else	hi = mid;
    	}
    	hi = lo - 1 + len;
    	while(lo <= hi){
    		mid = lo + (hi - lo) / 2;
    		real_mid = mid % len;
    		if(nums[real_mid] == target)	return true;
    		else if(nums[real_mid] < target) lo = mid + 1;
    		else hi = mid - 1;
    	}
    	return false;
    }
};
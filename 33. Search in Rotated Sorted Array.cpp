class Solution2 {
public:
    int search(vector<int>& nums, int target) {
    	int len = nums.size();
    	int lo = 0, hi=len - 1;
    	while(lo < hi){
    		int mid = (lo + hi) >> 1;
    		if(nums[mid] > nums[hi]) lo = mid + 1;
    		else hi = mid;
    	}
    	int rot = lo;
    	lo = 0, hi =len- 1;
    	while(lo <= hi){
    		int mid = (lo + hi) / 2;
    		int realmid = (mid + rot) % len;
    		if(nums[realmid] == target) return realmid;
    		if(nums[realmid] < target) lo=mid+1;
    		else hi = mid-1;
    	}
    	return -1;
    }
};
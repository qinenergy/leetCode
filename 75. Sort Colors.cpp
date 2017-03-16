class Solution2 {
public:
    void sortColors(vector<int>& nums) {
    	int len = nums.size();
    	int low(0), high(len-1), i(0);
    	while(i <= high){
    		if(nums[i] < 1)
    			swap(nums[i++], nums[low++]);
    		else if(nums[i] > 1)
    			swap(nums[i], nums[high--]);
    		else
    			++i;
    	}
    }
};
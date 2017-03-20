class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
    	int len = nums.size();
    	if(len == 0)	return INT_MIN;
    	int maxSum = nums[0], sum = 0;
    	for(auto& val : nums){
    		sum += val;
    		maxSum = max(sum, maxSum);
    		sum = max(sum, 0);
    	}
    	return maxSum;
    }
};
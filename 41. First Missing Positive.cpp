class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size(), n;
        for(int start = 0; start < len; ++start){
        	if(start + 1 == nums[start]) continue;
        	n = nums[start];
            while(n >= 1 && n <= len && n != nums[n - 1])
                swap(n, nums[n - 1]);
        }
        for(int start = 0; start < len; ++start){
        	if(nums[start] != start + 1)
        		return start + 1;
        }
        return len + 1;
    }
};
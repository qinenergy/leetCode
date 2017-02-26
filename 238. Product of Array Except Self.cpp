class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int len = nums.size();
    	if (len == 0)	return vector<int>();
        vector<int> rst(len, 1);
        rst[len - 1] = nums[len - 1];
        rst[0] = nums[0];
        for(int i = len - 2; i > 0; --i)
        	rst[i] = nums[i] * rst[i + 1];
        int last = 1;
        for(int i = 0; i < len - 1; ++i){
        	rst[i] = last * rst[i + 1];
        	last = last * nums[i];
        }
        rst[len - 1] = lst;
        return rst;
    }
};
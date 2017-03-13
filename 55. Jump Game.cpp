class Solution2 {
public:
    bool canJump(vector<int>& nums) {
    	int len = nums.size(); 
    	if(len <= 1)	return true;
    	int last = len - 1;
    	for(int i = len - 2; i >= 0; --i){
    		if(nums[i] == 0 || i + nums[i] < last) continue;
    		else last = i;
    	}
    	return last == 0;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)	return 0;
        int last(nums[0]), cnt = 1, i = 1, j = 1;
        while(i < len && j < len){
        	if(nums[j] != last){
        		last = nums[j];
        		cnt = 1;
        		nums[i++] = nums[j++];
        	}
        	else{
        		if(cnt < 2){
        			++cnt;
	        		nums[i++] = nums[j++];
        		}
        		else ++j;
        	}
        }
        return i;
    }
};
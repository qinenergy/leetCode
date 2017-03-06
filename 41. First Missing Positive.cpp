class Solution1 {
private:
    int swapMe(vector<int>& nums, int i, int depth){
        if(nums[i]<=0 || nums[i]>nums.size() || nums[i] == i+1 ||depth > nums.size()){
            return 1;
        }
        swapMe(nums, nums[i]-1, ++depth);
        swap(nums[i], nums[nums[i]-1]);
        return 1;
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        for(int i=0; i<nums.size(); i++)
            if(nums[i]>0 && nums[i]<=nums.size()) 
                swapMe(nums, i, 1);
        for(int i=0; i<nums.size(); i++)
            if(nums[i]<=0 || nums[i]>nums.size() || nums[i]!=i+1)
                return i+1;
        int max = *max_element(nums.begin(), nums.end());
        return max + 1;
    }
};

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

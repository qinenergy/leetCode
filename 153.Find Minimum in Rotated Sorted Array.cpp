class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 0;
        else if(len == 1) return nums[0];
        else if(len == 2) return min(nums[0], nums[1]);
        else if(len == 3) return min(nums[0], min(nums[1], nums[2]));
        else{
            int mid = len/2;
            if(nums[0] <= nums[mid-1]){
                vector<int> sub(&nums[mid], &nums[len]);
                return min(nums[0],findMin(sub));
            }
            else{
                vector<int> sub(&nums[0], &nums[mid]);
                return min(nums[0],findMin(sub));
            }
        }
        
        
    }
};

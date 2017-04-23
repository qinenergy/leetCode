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

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)    return INT_MIN;
        int lo(0), hi(len - 1), mid;
        while(lo <= hi){
            mid = (lo + hi) >> 1;
            if(nums[lo] <= nums[hi]) return nums[lo];
            else{
                if(nums[mid] >= nums[lo])    lo = mid + 1;
                else    hi = mid;
            }
        }
    }
};
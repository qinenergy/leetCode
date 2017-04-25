class Solution2 {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)    return -1;
        if(len == 1)    return 0;
        if(nums[0] > nums[1])   return 0;
        if(nums[len - 1] > nums[len - 2])   return len - 1;
        /*
         *  o(N) time complexity
         *  for(int i = 1; i < len - 1; ++i){
         *      if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
         *          return i;
         *  }
         */
         
         // o(logN) time complexity
        int lo = 1, hi = len - 2, mid;
        while(lo <= hi){
            mid = (hi + lo) >> 1;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if(nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
};
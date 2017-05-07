class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size()-1, nums.size()-k+1);
    }
    int helper(vector<int>& nums, int left, int right, int k){
        if(left==right) return nums[left];
        int i=left, j=right;
        int pivot = nums[int((i+j))/2];
        while(i<=j){
            while(i<=j && nums[i]<pivot)
                i++;
            while(i<=j && nums[j]>pivot)
                j--;
            if(i<=j){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        if(left+k-1<=j)
            return helper(nums, left, j, k);
        if(left+k-1<i)
            return nums[left+k-1];
        return helper(nums, i, right, k-i+left);
    }
};


class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();        
        if(size < k)    throw new runtime_error("invalid");
        int lo = 0, hi = size, p;
        while(lo < hi){
            p = (lo + hi) >> 1;
            p = partition(nums, lo, hi, p) + 1;
            if(p == k)  return nums[p - 1];
            else if(p > k)  hi = p - 1;
            else lo = p;
        }
    }
    int partition(vector<int>& nums, int start, int end, int p){
        int pivot = nums[p];
        swap(nums[start], nums[p]);
        while(start < end){
            while(start < end && nums[start] > nums[--end]);
            swap(nums[start], nums[end]);
            while(start < end && nums[++start] > nums[end]);
            swap(nums[start], nums[end]);
        }
        nums[start] = pivot;
        return start;
    }
};
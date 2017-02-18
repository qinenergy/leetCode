class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i(0), j(0);
        for(i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};

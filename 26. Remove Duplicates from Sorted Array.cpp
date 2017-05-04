class Solution {

public:

    int removeDuplicates(vector<int>& nums) {

        int cnt = 0, current = INT_MIN;

        for(int i = 0; i< nums.size(); i++){

            if (nums[i]>current){

                nums[cnt] = nums[i];

                cnt += 1;

                current = nums[i];

            }

        }

        return cnt;

    }

};

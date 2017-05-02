class Solution {

public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;

        if(nums.size()<3) return res;

        sort(nums.begin(), nums.end());

        for(int p=0; p< nums.size()-2; p++){

            if(p!=0 && nums[p]==nums[p-1])

                continue;

            int i(p+1), j(nums.size()-1);

            int target = - nums[p];

            while(i < j){

                if(nums[i] + nums[j] == target){

                    vector<int> triple;

                    triple.push_back(-target);

                    triple.push_back(nums[i]);

                    triple.push_back(nums[j]);

                    res.push_back(triple);

                    i++;

                    j--;

                    while(i<j && nums[i] == nums[i-1]) i++;

                    while(i<j && nums[j] == nums[j+1]) j--;

                }

                else if(nums[i] + nums[j] < target) i++;

                else j--;

            }

        }

        return res;

    }

};

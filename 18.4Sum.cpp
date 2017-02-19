class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        int l,r,sum;
        int len = nums.size();
        for(int i=0; i< len-3; i++){
            if( i!=0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<len-2; j++){
                if(j!=i+1 && nums[j] == nums[j-1])
                    continue;
                l = j+1;
                r = len-1;
                while(l < r){
                    sum = nums[i]+nums[j]+nums[l]+nums[r];
                    if( sum == target){
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while( l< r && nums[l] == nums[l-1])
                            l++;
                        while( l< r && nums[r] == nums[r+1])
                            r--;
                    }
                    else if (sum < target)
                        l++;
                    else
                        r--;
                }
            }
        }
        return res;
    }
};

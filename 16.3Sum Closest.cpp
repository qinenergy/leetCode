class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=0;
        if(nums.size()<3) return -1;
        sort(nums.begin(), nums.end());
        int min_distance = INT_MAX;
        int j,k, distance;
        for(int i=0; i<nums.size()-2; i++){
            j = i + 1;
            k = nums.size() - 1;
            while(j<k){
                distance = target - nums[i] - nums[j] - nums[k];
                if(abs(distance) < min_distance){
                    min_distance = abs(distance);
                    res = nums[i] + nums[j] + nums[k];
                }
                if(distance<0)
                    k--;
                else if (distance>0)
                    j++;
                else
                    return res;
            }
        }
        return res;
    }
};

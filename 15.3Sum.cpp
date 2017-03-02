class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int j = i + 1;
            int k = nums.size()-1;
            while( j < k){
                vector<int> curr;
                if(nums[i]+nums[j]+nums[k]==0){
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[k]);
                    res.push_back(curr);
                    ++j;
                    --k;
                    while(j < k && nums[j-1]==nums[j])
                        j++;
                    while(j < k && nums[k+1]==nums[k])
                        k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0)
                    j++;
                else
                    k--;
            }
            while(i< nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return {};
        vector<vector<int>> rst;    
        sort(nums.begin(), nums.end());
        int start = 0, mid = 1, end = len - 1, sum;
        for(int start = 0; start < len - 2;){
            mid = start + 1, end = len - 1;
            while(mid < end){
                sum = nums[start] + nums[mid] + nums[end];
                if(sum == 0){
                    rst.push_back(vector<int>{nums[start], nums[mid], nums[end]});
                    ++mid;
                    --end;
                    while(mid < end && nums[mid] == nums[mid - 1]) ++mid;
                    while(end > mid && nums[end] == nums[end + 1])  ++end;
                }
                else if(sum < 0){
                    ++mid;
                    while(mid < end && nums[mid] == nums[mid - 1])  ++mid;  
                }
                else{
                    --end;
                    while(end > mid && nums[end] == nums[end + 1])  --end;
                }
            }
            ++start;
            while(start < len - 2 && nums[start] == nums[start - 1])    ++start;
        }
        return rst;
    }
};

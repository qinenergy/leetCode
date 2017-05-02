class Solution {

public:

    int minSubArrayLen(int s, vector<int>& nums) {

        int sum = 0;

        int min_len = INT_MAX;

        int start(0), end(0);

        while(start < nums.size() && end < nums.size()){

            while(sum < s && end < nums.size()){

                sum += nums[end];

                end++;

            }

            while(sum >=s && start < end){

                min_len = min(min_len, end-start);

                sum -= nums[start];

                start++;

            }

        }

        return min_len==INT_MAX ? 0: min_len;

    }

};

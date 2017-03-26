class NumArray {
public:
    NumArray(vector<int> nums) {
        _len = nums.size();
        _acc = vector<int>(_len + 1, 0);
        for(int i = 0; i < _len; ++i)
            _acc[i + 1] = _acc[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        if(i > j || i >= _len || j >= _len || i < 0 || j < 0)
            throw new runtime_error("invalid i and j");
        return _acc[j + 1] - _acc[i];
    }
private:
    vector<int> _acc;
    int _len;
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();    
        auto rs = NumArray(nums);
        vector<vector<int>> dp(len, vector<int>(len , 0));
        for(int i = 0; i < len; ++i)
            dp[i][i] = nums[i];
        for(int k = 1; k < len; ++k){
            for(int i = 0; i < len - k; ++i){
                dp[i][k + i] = max(
                    nums[i] + rs.sumRange(i + 1, k + i) - dp[i + 1][k + i],
                    nums[k + i] + rs.sumRange(i, k + i - 1) - dp[i][k + i - 1]
                );
            }
        }
        int total = rs.sumRange(0, len - 1);
        if(dp[0][len - 1] * 2 < total)
            return false;
        return true;
    }
};
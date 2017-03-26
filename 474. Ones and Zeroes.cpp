class Solution2 {
public:
    int numOfZero(const string& str){
        int cnt = 0;
        for(auto& ch : str)
            ch == '0' ? cnt += 1 : cnt += 0;
        return cnt;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size(), size, num_zero, num_one;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(auto& str : strs){
            size = static_cast<int>(str.size());
            num_zero = numOfZero(str), num_one = size - num_zero;
            for(int r0 = m; r0 >= num_zero; --r0)
                for(int r1 = n; r1 >= num_one; --r1)
                    dp[r0][r1] = max(dp[r0][r1], dp[r0 - num_zero][r1 - num_one] + 1);
        }
        return dp[m][n];
    }
};
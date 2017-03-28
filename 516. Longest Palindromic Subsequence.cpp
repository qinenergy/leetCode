class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();       
        if(len <= 1)    return len;
        vector<vector<int>> dp(len, vector<int>(len, 1));
        for(int k = len - 2; k >= 0; --k){
            for(int i = len - 1, j = 0; i >= len - k - 1; --i, ++j)
                if(s[k - j] == s[i]){
                    if(k - j == i - 1)  dp[k - j][i] = 2;
                    else    dp[k - j][i] = dp[k - j + 1][i - 1] + 2;
                }
                else    dp[k - j][i] = max(dp[k - j][i - 1], dp[k - j + 1][i]);
            }
        }
        return dp[0][len - 1];
    }
};
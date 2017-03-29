class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if(row == 0)    return 0;
        vector<int> dp(row, 0);
        for(int i = row - 1; i >= 0; --i)
            for(int j = 0; j <= i; ++j)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        return dp[0];
    }
};
class Solution2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)   return 0;
        int cols = matrix[0].size();
        if(cols == 0)   return 0;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int max_edge = 0;
        for(int r = rows - 1; r >= 0; --r){
            for(int c = cols - 1; c >= 0; --c){
                if(matrix[r][c] == '0')   dp[r][c] = 0;
                else{
                    if(r == rows - 1 || c == cols - 1)  dp[r][c] = 1;
                    else dp[r][c] = min(dp[r+1][c], min(dp[r][c+1], dp[r+1][c+1])) + 1;
                    if(dp[r][c] > max_edge) max_edge = dp[r][c];
                }
            }
        }
        return max_edge * max_edge;
    }
};

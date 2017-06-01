class Solution2 {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows == 0)   return;
        int cols = board[0].size();
        for(int i = 0; i < rows; ++i){
            check(board, i, 0, rows, cols);
            if(cols > 1)    check(board, i, cols - 1, rows, cols);
        }
        for(int j = 0; j < cols; ++j){
            check(board, 0, j, rows, cols);
            if(rows > 1)    check(board, rows - 1, j, rows, cols);
        }
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                board[i][j] == '1' ? board[i][j] = 'O' : board[i][j] = 'X';
    }
    void check(vector<vector<char>>& board, int i, int j, int rows, int cols){
        if(board[i][j] == 'O'){
            board[i][j] = '1';
            if(i > 1)   check(board, i - 1, j, rows, cols);
            if(j > 1)   check(board, i, j - 1, rows, cols);
            if(i < rows - 1) check(board, i + 1, j, rows, cols);
            if(j < cols - 1) check(board, i, j + 1, rows, cols);
        }
    }
};

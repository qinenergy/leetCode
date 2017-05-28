class Solution2 {
public:
    void traverse(const vector<vector<char>>& grid,
        vector<vector<bool>>& visited, int i, int j, int rows, int cols){
        visited[i][j] = true;
        if(i > 0 && !visited[i - 1][j] && grid[i - 1][j] == '1')
            traverse(grid, visited, i - 1, j, rows, cols);
        if(i < rows - 1 && !visited[i + 1][j] && grid[i + 1][j] == '1')
            traverse(grid, visited, i + 1, j, rows, cols);
        if(j > 0 && !visited[i][j - 1] && grid[i][j - 1] == '1')
            traverse(grid, visited, i, j - 1, rows, cols);
        if(j < cols - 1 && !visited[i][j + 1] && grid[i][j + 1] == '1')
            traverse(grid, visited, i, j + 1, rows, cols);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), num = 0;
        if(rows == 0)   return 0;
        int cols = grid[0].size();
        if(cols == 0)   return 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; ++i){
            auto& vi = visited[i];
            auto& gi = grid[i];
            for(int j = 0; j < cols; ++j){
                if(gi[j] == '0' || vi[j])   continue;
                traverse(grid, visited, i, j, row, cols);
                ++num;
            }
        }
        return num;
    }
};

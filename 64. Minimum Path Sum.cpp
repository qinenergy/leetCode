class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0)	return 0;
        int cols = grid[0].size();
        if(cols == 0)	return 0;
        vector<int> sums(cols, 0);
        for(int i = 0; i < rows; ++i){
        	for(int j = 0; j < cols; ++j){
        		if(j == 0)
        			sums[j] = sums[j] + grid[i][j];
        		else{
        			if(i == 0)
        				sums[j] = sums[j - 1] + grid[i][j];
    				else
	        			sums[j] = min(sums[j - 1], sums[j]) + grid[i][j];
        		}
        	}
        }
        return sums[col - 1];
    }
};
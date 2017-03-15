class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int rows = obstacleGrid.size(); 
    	if(rows <= 0)	throw new runtime_error("invalid input");
    	int cols = obstacleGrid[0].size();
    	if(cols <= 0)	throw new runtime_error("invalid input");
    	if(obstacleGrid[0][0] == 1)	return 0;
    	vector<int> counts = vector<int>(cols, 1);
    	for(int i = 0; i < rows; ++i){
    		for(int j = 0; j < cols; ++j){
    			if(obstacleGrid[i][j] == 1)
    				counts[j] = 0;
    			else{
    				if(i == 0 && j > 0)
    					counts[j] = counts[j - 1] == 0 ? 0 : 1;
    				else if(j == 0 && i > 0)
    					counts[j] = counts[j] == 0 ? 0 : 1;
    				else
    					counts[j] = counts[j - 1] + counts[j];
    			}
    		}
    	}
    	return counts[cols - 1];
    }
};
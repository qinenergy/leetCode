class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)	return;
        int cols = matrix[0].size();
        if(cols == 0)	return;
        int col0 = 1;
        for(int i = 0; i < rows; ++i){
        	col0 = col0 && (matrix[i][0] != 0);
        	for(int j = 0; j < cols; ++j){
        		if(matrix[i][j] == 0){
        			matrix[0][j] = 0;
        			matrix[i][0] = 0;
        		}
        	}
        }
        for(int i = rows - 1; i >= 0; --i)
        	for(int j = cols - 1; j >= 0; --j)
        		if((j != 0 && matrix[0][j] == 0)|| (j == 0 && col0 == 0) || matrix[i][0] == 0)
        		    matrix[i][j] = 0;
    }
};
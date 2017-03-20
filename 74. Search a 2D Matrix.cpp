class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();        
		if(rows == 0)	return false;
		int cols = matrix[0].size();
		if(cols == 0)	return false;
		int i = 0, j = cols - 1;
		while(j >= 0 && i < rows){
			if(matrix[i][j] == target)	return true;
			else if(matrix[i][j] < target) ++i;
			else --j;
		}
		return false;
    }
};
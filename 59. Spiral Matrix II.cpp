class Solution1 {
public:
    int dir(vector<vector<int>>& matrix, int direction, int i, int j){
        int rows = matrix.size();
        int columns = matrix[0].size();
        if(direction == 0){
            if(j == columns - 1) return 1;
            else if(matrix[i][j+1] != 0) return 1;
            else return 0;
        }
        if(direction == 1){
            if(i == rows - 1) return 2;
            else if(matrix[i+1][j] != 0) return 2;
            else return 1;
        }
        if(direction == 2){
            if(j == 0) return 3;
            else if(matrix[i][j-1] != 0) return 3;
            else return 2;
        }
        if(direction == 3){
            if(i == 0) return 4;
            else if(matrix[i-1][j] != 0) return 0;
            else return 3;
        }
        return -1;
    }
    void update(int direction, int& i, int& j){
        if(direction == 0) j++;
        if(direction == 1) i++;
        if(direction == 2) j--;
        if(direction == 3) i--;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int direction = 0;
        int i(0), j(0);
        for(int t=0; t<n*n; t++){
            res[i][j] = t+1;
            direction = dir(res, direction, i, j);
            update(direction, i, j);
        }
        return res;
    }
};
class Solution2 {
public:
    vector<vector<int>> generateMatrix(int n) {
    	if(n == 0) return vector<vector<int>>();
    	vector<vector<int>> rst(n, vector<int>(n, 1));
    	spiral(rst, 1, 0, n, 0, n);
    	return rst;
    }
    void spiral(vector<vector<int>>& rst, int last, int sr, int er, int sc, int ec){
    	if(sr >= er || sc >= ec)	return;
    	int i;
    	for(i = sc; i < ec; ++i)
    		rst[sr][i] = last++;
    	for(i = sr + 1; i < er; ++i)
    		rst[i][ec - 1] = last++;
    	for(i = ec - 2; i >= sc && sr != er - 1; --i)
    		rst[er - 1][i] = last++;
    	for(i = er - 2; i >= sr + 1 && sc != ec - 1; --i)
    		rst[i][sc] = last++;
    	spiral(rst, last, sr + 1, er - 1, sc + 1, ec - 1);
    	return;
    }
};

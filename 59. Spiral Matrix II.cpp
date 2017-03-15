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
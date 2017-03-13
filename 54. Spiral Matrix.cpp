class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> rst;
		int row = matrix.size();
		if (row == 0)	return rst;
		int col = matrix[0].size();
		if (col == 0)	return rst;
		spiralTraverse(matrix, rst, 0, 0, row, col);
		return rst;
	}
	void spiralTraverse(vector<vector<int>>& matrix, vector<int>& rst, int sr, int sc, int er, int ec) {
		if (sr >= er || sc >= ec)	return;
		int i;
		for (i = sc; i < ec; ++i)
			rst.push_back(matrix[sr][i]);
		for (i = sr + 1; i < er; ++i)
			rst.push_back(matrix[i][ec - 1]);
		for (i = ec - 2; i >= sc && sr != er - 1; --i)
			rst.push_back(matrix[er - 1][i]);
		for (i = er - 2; i > sr && sc != ec - 1; --i)
			rst.push_back(matrix[i][sc]);
		spiralTraverse(matrix, rst, sr + 1, sc + 1, er - 1, ec - 1);
	}
};
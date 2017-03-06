class Solution2 {
public:
	void rotate(vector<vector<int>>& matrix) {
		int N = matrix.size();
		if (N <= 1)	return;
		int temp, r, s;
		for (int c = N; c > 1; c -= 2) {
			r = (N - c) / 2;
			s = (N + c) / 2 - 1;
			for (int i = 0; i < c - 1; ++i) {
				for (int j = 0; j < 4; ++j) {
					switch (j) {
						case 0:
						temp = matrix[r + i][s];
						matrix[r + i][s] = matrix[r][r + i];
						break;
						case 1:
						swap(matrix[s][s - i], temp);
						break;
						case 2:
						swap(matrix[s - i][r], temp);
						break;
						case 3:
						swap(matrix[r][r + i], temp);
						break;
						default:
						break;
					}
				}
			}
		}
	}
};
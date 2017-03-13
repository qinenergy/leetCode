class Solution2 {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
		int len2 = word2.size();
		if (len1 == 0) return len2;
		if (len2 == 0) return len1;

		// Cost matrix
		vector<vector<int>> dist;
		for (int i = 0; i <= len1; ++i) {
			dist.push_back(vector<int>(len2 + 1));
			dist[i][0] = i;
		}
		for (int j = 0; j <= len2; ++j)
			dist[0][j] = j;

		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {
				if (word1[i - 1] == word2[j - 1])
					dist[i][j] = dist[i - 1][j - 1];
				else
					dist[i][j] = min(min(dist[i - 1][j], dist[i - 1][j - 1]), dist[i][j - 1]) + 1;
			}
		}
		return dist[len1][len2];
    }
};
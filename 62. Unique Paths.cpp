class Solution2 {
public:
    int uniquePaths(int m, int n) {
 		if(m==0 || n==0)	return 0;
 		vector<int> counts(n, 1);
 		for(int i = 1; i < m; ++i)
 			for(int j = 1; j < n; ++j)
 				counts[j] = counts[j] + counts[j - 1];
 		return counts[n - 1];
    }
};
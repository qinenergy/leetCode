class Solution2 {
public:
    int numTrees(int n) {
        vector<int> nbsts(n + 1, 0);
        nbsts[0] = 1, nbsts[1] = 1, nbsts[2] = 2;
        for(int i = 3; i <= n; ++i)
        	for(int root = 1; root <= n; ++root)
        		nbsts[i] += nbsts[root - 1] * nbsts[i - root];
        return nbsts[n];
    }
};
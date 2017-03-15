class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        res = [[0] * n for i in range(m)]
        if obstacleGrid[0][0] != 1:
            res[0][0] = 1
        for i in range(1, m):
            res[i][0] = res[i-1][0]
            if obstacleGrid[i][0] == 1:
                res[i][0] = 0;
        for i in range(1, n):
            res[0][i] = res[0][i-1]
            if obstacleGrid[0][i] == 1:
                res[0][i] = 0;
        for i in range(1,m):
            for j in range(1,n):
                res[i][j] = res[i][j-1] + res[i-1][j]
                if obstacleGrid[i][j] == 1:
                    res[i][j] =0
        return res[m-1][n-1]
        

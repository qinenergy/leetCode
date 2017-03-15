class Solution(object):
    def update(self, direction,res, i, j):
        m, n = len(res), len(res[0])
        if direction == 0:
            if j==n-1: 
                return 1, i+1,j
            if res[i][j+1]!=0:
                return 1, i+1,j
            else:
                return 0, i, j+1
        if direction == 1:
            if i==m-1: 
                return 2, i, j-1
            if res[i+1][j]!=0:
                return 2, i,j-1
            else:
                return 1, i+1, j
        if direction == 2:
            if j==0: 
                return 3, i-1,j
            if res[i][j-1]!=0:
                return 3, i-1,j
            else:
                return 2, i, j-1
        if direction == 3:
            if i==0: 
                return 0, i,j+1
            if res[i-1][j]!=0:
                return 0, i,j+1
            else:
                return 3, i-1, j
        
    
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        res = [[0]*n for x in range(n)]
        i, j, direction = 0, 0, 0
        for t in range(n*n):
            res[i][j] = t+1
            direction, i, j = self.update(direction, res, i, j)
        return res
        

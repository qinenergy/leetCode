class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = []
        for i in range(numRows):
            resl = []
            for j in range(i+1):
                if j == 0:
                    resl.append(1);
                elif j == i:
                    resl.append(1);
                else:
                    resl.append(res[i-1][j-1]+res[i-1][j])
            res.append(resl);  
        return res
        

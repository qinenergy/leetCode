class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        n = rowIndex + 1
        res = [1] * (n)
        for i in range(2, n):
            for j in range(i-1, 0, -1):
                res[j] = res[j] + res[j-1]
        return res

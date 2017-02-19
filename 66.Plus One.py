class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        res = []
        plus = 1
        for i in range(len(digits)-1, -1, -1):
            digit = digits[i] + plus
            if digit>9:
                plus = 1
            else:
                plus = 0
            res.append(digit%10)
        if plus == 1 :
            res.append(1)
        return res[::-1]
        

class Solution(object):

    def readBinaryWatch(self, num):

        """

        :type num: int

        :rtype: List[str]

        """

        ans=[]

        for i in range(2**10):

            if(bin(i).count('1')==num):

                minute = i & 0b0000111111

                hour = i>>6

                if hour<12 and minute<60:

                    ans.append("%d:%02d"%(hour, minute))

        return ans

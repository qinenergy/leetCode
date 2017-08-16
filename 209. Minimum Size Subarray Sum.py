class Solution(object):

    def minSubArrayLen(self, s, nums):

        """

        :type s: int

        :type nums: List[int]

        :rtype: int

        """

        start, end = 0, 0

        min_len = sys.maxsize

        sum = 0

        while(start<len(nums) and end<len(nums)):

            while(sum < s and end < len(nums)):

                sum += nums[end]

                end += 1

            while(sum >= s and start <end):

                if(end-start < min_len):

                    min_len = end - start

                sum -= nums[start]

                start += 1

        if min_len == sys.maxsize:

            min_len = 0

        return min_len

            

        

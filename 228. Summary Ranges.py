class Solution(object):

    def summaryRanges(self, nums):

        """

        :type nums: List[int]

        :rtype: List[str]

        """

        left, right = -sys.maxsize, sys.maxsize

        ans = []

        n = len(nums)

        if n==0: 

            return ans

        for i in range(n):

            if left == -sys.maxsize:

                left = nums[i]

                right = nums[i]

            elif nums[i] == right + 1:

                right = nums[i]

            else:

                if(left!=right):

                    ans.append(str(left) + "->" + str(right))

                else:

                    ans.append(str(left))

                left = nums[i]

                right = nums[i]

        if(left!=right):

            ans.append(str(left) + "->" + str(right))

        else:

            ans.append(str(left))

        return ans

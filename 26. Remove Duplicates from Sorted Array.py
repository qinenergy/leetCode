class Solution(object):

    def removeDuplicates(self, nums):

        """

        :type nums: List[int]

        :rtype: int

        """

        current = -sys.maxint

        currenti = 0

        for i in range(len(nums)):

            if nums[i] > current:

                nums[currenti] = nums[i]

                current = nums[i]

                currenti += 1

        return currenti

                

        

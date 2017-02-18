class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        for j, x in enumerate(nums):
            if x != val:
                nums[i] = nums[j]
                i = i + 1
        return i
                

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        elif n == 2:
            return min(nums[0], nums[1])
        elif n == 3:
            return min(nums[2], min(nums[0], nums[1]))
        mid = n/2
        if nums[0] < nums[mid-1]:
            return min(nums[0], self.findMin(nums[mid:]))
        elif nums[0] > nums[mid-1]:
            return min(nums[0], self.findMin(nums[:mid]))
        else:
            return self.findMin(nums[1:])
        

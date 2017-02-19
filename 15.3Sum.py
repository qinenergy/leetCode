class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = list(list())
        if len(nums) < 3:
            return res
        nums.sort()
        i = 0
        while i<len(nums):
            j = i+1;
            k = len(nums)-1;
            while (j < k):
                if nums[i] + nums[j] + nums[k] == 0 :
                    res.append([nums[i], nums[j], nums[k]])
                    j, k = j+1, k-1
                    while j < k and nums[j] == nums[j-1]:
                        j = j + 1
                    while j < k and nums[k] == nums[k+1]:
                        k = k - 1
                elif nums[i] + nums[j] + nums[k] < 0 :
                    j = j + 1
                else:
                    k = k - 1
            while i < len(nums)-1 and nums[i] == nums[i+1]:
                i = i + 1
            i = i + 1
        return res
                
                
        

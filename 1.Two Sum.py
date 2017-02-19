class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = []
        if len(nums) < 2:
            return res
        myMap = dict(zip(nums, range(len(nums))))
        for i, x in enumerate(nums):
            need = target - x
            if need in myMap:
                index = myMap[need]
                if index != i:
                    return [i, index]
         

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res = 0;
        if len(nums)<3 : 
            return -1
        min_distance = sys.maxint;
        nums.sort()
        for i in range(len(nums)):
            j = i+1
            k = len(nums) -1;
            while j<k :
                distance = target - nums[i] - nums[j] - nums[k]
                if abs(distance) < min_distance:
                    min_distance = abs(distance)
                    res = nums[i] + nums[j] + nums[k]
                if distance < 0:
                    k = k - 1
                elif distance > 0:
                    j = j + 1
                else:
                    return target
        return res
        
        

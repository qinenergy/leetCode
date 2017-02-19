class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = list(list())
        if len(nums)<4:
            return res
        nums.sort()
        n = len(nums)
        for i in range(0, n-3):
            if i!=0 and nums[i]==nums[i-1]:
                continue
            for j in range(i+1, n-2):
                if j!= i+1 and nums[j] == nums[j-1]:
                    continue
                l, r = j+1, n-1
                while l < r:
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if sum == target:
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                        l, r = l+1, r-1
                        while l<r and nums[l]==nums[l-1]:
                            l = l + 1;
                        while l<r and nums[r]==nums[r+1]:
                            r = r - 1;
                    elif sum < target:
                        l = l + 1;
                    else:
                        r = r - 1;
        return res
                        

class Solution(object):

    def threeSum(self, nums):

        """

        :type nums: List[int]

        :rtype: List[List[int]]

        """

        nums.sort()

        result = []

        for pointer in range(len(nums)-2):

            if pointer > 0 and nums[pointer] == nums[pointer-1]:

                continue

            i, j = pointer+1, len(nums)-1

            target = -nums[pointer]

            while(i<j):

                if nums[i] + nums[j] == target:

                    result.append([-target, nums[i], nums[j]])

                    i = i + 1

                    j = j - 1

                    while i<j and nums[i]==nums[i-1]:

                        i += 1

                    while i<j and nums[j]==nums[j+1]:

                        j -= 1

                elif nums[i] + nums[j] < target:

                    i = i + 1

                else:

                    j = j - 1

        return result

        

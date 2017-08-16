class Solution(object):

    def removeDuplicates(self, nums):

        """

        :type nums: List[int]

        :rtype: int

        """

        cnt = 0

        dpl = 0

        current = -sys.maxsize

        for i in range(len(nums)):

            if nums[i]>current:

                nums[cnt] = nums[i]

                current = nums[cnt]

                cnt += 1

                dpl = 1

            elif nums[i]==current and dpl==1:

                nums[cnt] = current

                dpl += 1

                cnt += 1

        return cnt

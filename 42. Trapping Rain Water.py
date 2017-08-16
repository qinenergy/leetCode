class Solution(object):

    def trap(self, height):

        """

        :type height: List[int]

        :rtype: int

        """

        n = len(height)

        left_max = [0] * n

        for i in range(1,n):

            left_max[i] = max(left_max[i-1], height[i-1])

        right_max = [0] * n

        for i in range(n-2, -1, -1):

            right_max[i] = max(right_max[i+1], height[i+1])

        ans = 0

        for i in range(n):

            sr = min(left_max[i], right_max[i])

            if sr > height[i]:

                ans += sr - height[i]

        return ans

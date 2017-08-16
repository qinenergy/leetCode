class Solution(object):

    def maxArea(self, height):

        """

        :type height: List[int]

        :rtype: int

        """

        left, right = 0, len(height)-1

        max_size = (right-left) * min(height[left], height[right])

        while(left<right):

            if height[left]<height[right]:

                left += 1

            else:

                right -= 1

            max_size = max(max_size, (right-left) * min(height[left], height[right]))

        return max_size

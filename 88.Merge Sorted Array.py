class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        i, j = m-1, n-1;
        for k in range(m+n-1, -1 ,-1):
            if i>=0 and j>=0: 
                if nums1[i] > nums2[j]:
                    nums1[k] = nums1[i]
                    i = i - 1
                elif j>=0:
                    nums1[k] = nums2[j]
                    j = j - 1
            elif i>=0:
                nums1[k] = nums1[i]
                i = i - 1
            else:
                nums1[k] = nums2[j]
                j = j - 1
        

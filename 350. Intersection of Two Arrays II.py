class Solution(object):

    def intersect(self, nums1, nums2):

        """

        :type nums1: List[int]

        :type nums2: List[int]

        :rtype: List[int]

        """

        hash = collections.Counter()

        for i in nums1:

            hash[i]+=1

        res = []

        for j in nums2:

            if hash[j]>0:

                hash[j]-=1

                res.append(j)

        return res

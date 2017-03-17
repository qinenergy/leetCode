class Solution(object):
    def findk(self, n1,n2,k):
        if len(n1)>len(n2):
            return self.findk(n2,n1,k)
        if len(n1)==0:
            return n2[k-1]
        if k==1:
            return min(n1[0], n2[0])
        pa = min(len(n1), k/2)
        pb = k - pa
        if (n1[pa-1] < n2[pb-1]):
            return self.findk(n1[pa:], n2, k-pa)
        elif (n1[pa-1] > n2[pb-1]):
            return self.findk(n1, n2[pb:], k-pb)
        else:
            return n1[pa-1]
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        t = len(nums1)+len(nums2)
        if t%2==0:
            return ( self.findk(nums1,nums2,t/2) + self.findk(nums1,nums2,t/2+1) )/2.0
        else:
            return self.findk(nums1,nums2,t/2+1)
        
      

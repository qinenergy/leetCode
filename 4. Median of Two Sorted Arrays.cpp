class Solution {
public:
    double findk(int a[], int m, int b[], int n, int k){
        if(m>n) return findk(b, n, a, m, k);
        else if(m==0) return b[k-1];
        else if(k==1) return min(a[0], b[0]);
        int pa = min(k/2, m);
        int pb = k-pa;
        if (a[pa-1]<b[pb-1]) return findk(a+pa, m-pa, b,n,k-pa);
        else if (a[pa-1]>b[pb-1]) return findk(a, m, b+pb,n-pb,k-pb);
        else return a[pa-1];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if((m+n)%2==0) return (findk(nums1.data(),m,nums2.data(),n, int((m+n)/2))+ findk(nums1.data(),m,nums2.data(),n, int((m+n)/2)+1))/2; 
        else return findk(nums1.data(),m,nums2.data(),n, int((m+n)/2)+1);
    }
};
class Solution2 {
public:
    double findK(vector<int>& nums1, int s1, int len1, vector<int>& nums2, int s2, int len2, int k){
        if(len1 - s1 > len2 - s2)   
            return findK(nums2, s2, len2, nums1, s1, len1, k);
        else if(s1 == len1)  
            return nums2[s2 + k - 1];
        else if(k == 1) 
            return min(nums1[s1], nums2[s2]);
        int ind1 = min(k / 2, len1 - s1);
        int ind2 = k - ind1;
        if(nums1[s1 + ind1 - 1] < nums2[s2 + ind2 - 1])
            return findK(nums1, s1 + ind1, len1, nums2, s2, len2, k - ind1);
        else if(nums1[s1 + ind1 - 1] > nums2[s2 + ind2 - 1]) 
            return findK(nums1, s1, len1, nums2, s2 + ind2, len2, k - ind2);
        else
            return nums1[s1 + ind1 - 1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int mid = (len1 + len2)/2;
        if((len1 + len2) % 2 == 0)   
            return (findK(nums1, 0, len1, nums2, 0, len2, mid) + findK(nums1, 0, len1, nums2, 0, len2, mid + 1)) / 2;
        else
            return findK(nums1, 0, len1, nums2, 0, len2, mid + 1);
    }
};

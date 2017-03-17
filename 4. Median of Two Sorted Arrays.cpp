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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        cout << "No idea right now T_T" << endl;
        return -1.0;
    }
};

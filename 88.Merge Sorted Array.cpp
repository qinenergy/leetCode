class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i(m-1), j(n-1);
        for(int k = m+n-1; k >= 0; k--){
            if(i >= 0 && j >= 0){
                if(nums1[i] > nums2[j]){
                    nums1[k] = nums1[i];
                    i--;
                }
                else{
                    nums1[k] = nums2[j];
                    j--;
                }
            }
            else if(i>=0){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
        }
    }
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     	int ia = m - 1, ib = n - 1, icur = m + n - 1;
    	while (ia >= 0 && ib >= 0) {
	    	nums1[icur--] = nums1[ia] >= nums2[ib] ? nums1[ia--] : nums2[ib--];
    	}
    	while (ib >= 0) {
	    	nums1[icur--] = nums2[ib--];
    	}
    }
};
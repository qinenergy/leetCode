class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for(auto i: nums1)
            hash[i]++;
        vector<int> res;
        for(auto i: nums2){
            if(hash[i]>0){
                res.push_back(i);
                hash[i]--;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
		int N2 = nums2.size();
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> result;
		int i = 0, j = 0;
		while (i < N1 && j < N2) {
			if (nums1[i] < nums2[j]) ++i;
			else if (nums2[j] < nums1[i]) ++j;
			else {
				result.push_back(nums1[i]);
				++i;
				++j;
			}
		}
		return result;
    }
};
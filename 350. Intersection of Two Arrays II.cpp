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

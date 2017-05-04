class Solution {

public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> hash;

        for(int i=0; i<nums1.size(); i++)

            hash[nums1[i]] += 1;

        set<int> numset(nums2.begin(), nums2.end());

        vector<int> res;

        for(auto i: numset){

            if(hash[i]>0)

                res.push_back(i);

        }

        return res;

    }

};

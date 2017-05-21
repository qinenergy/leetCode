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

class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(auto& val : nums1)  mp[val] = min(1, mp[val] + 1);
        for(auto& val : nums2)
            if(mp[val]-- > 0)
                res.push_back(val);
        return res;
    }
};
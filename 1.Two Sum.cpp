class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()<2) return res;
        unordered_map<int, int> myMap;
        for(int i=0; i<nums.size(); i++)
            myMap[nums[i]] = i;
        for(int i=0; i<nums.size(); i++){
            int need = target - nums[i];
            if(myMap.find(need)!=myMap.end()){
                int index = myMap.find(need)->second;
                if (index == i) continue;
                res.push_back(i);
                res.push_back(index);
                return res;
            }
        }
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)	return {};
        map<int, int> m;
        for(int i = 0; i < len; ++i)
        	m.insert({nums[i], i});
        for(int i = 0; i < len; ++i){
        	auto it = m.find(target - nums[i]);
        	if(it != m.end() && it->second != i)
        		return {i, it->second};
        }
        return {};
    }
};
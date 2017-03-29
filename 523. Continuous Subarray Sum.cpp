class Solution2 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> m;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (m.find(mod) != m.end()) return true;
            m.insert(pre);
            pre = mod;
        }
        return false;
    }
};
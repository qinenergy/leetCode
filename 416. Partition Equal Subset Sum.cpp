class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size(), sum = 0;
        const int max_len = 20000;
        if(len <= 1)    return false;
        bitset<max_len> bits(1);
        for(auto& val : nums){
            sum += val;
            bits |= bits << val;
        }
        return !(sum % 2) && bits[sum >> 1];
    }
};
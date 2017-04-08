class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto& val : nums){
            a = (a ^ val) & ~b;
            b = (b ^ val) & ~a;
        }
        return a;
    }
};
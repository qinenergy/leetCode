class Solution2 {
public:
    string getPermutation(int n, int k) {
        string dict(n, 0);
        iota(dict.begin(), dict.end(), '1');
        
        vector<int> fract(n, 1);
        for (int idx = n - 3; idx >= 0; --idx) {
            fract[idx] = fract[idx + 1] * (n - 1 - idx);
        }
        
        --k;
        
        string ret(n, 0);
        for (int idx = 0; idx < n; ++idx) {
            int select = k / fract[idx];
            k %= fract[idx];
            ret[idx] = dict[select];
            dict.erase(next(dict.begin(), select));
        }
        return ret;
    }
};
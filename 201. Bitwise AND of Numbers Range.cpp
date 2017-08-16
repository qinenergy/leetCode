class Solution2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (m < n) ? rangeBitwiseAnd(m >> 1, n >> 1) << 1 : m;
    }
};

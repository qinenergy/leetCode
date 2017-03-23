class Solution2 {
public:
    int numDecodings(string s) {
    	int pre = 0, ways0 = 0, ways1 = s.empty() ? 0 : 1;
        for (char c : s) {
            int cur = c - '0';
            int ways = (cur != 0 ? ways1 : 0) + (pre != 0 && (pre * 10 + cur) <= 26 ? ways0 : 0);
            ways0 = ways1, ways1 = ways, pre = cur;
        }
        return ways1;
    }
};
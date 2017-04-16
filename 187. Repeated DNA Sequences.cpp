class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> mp;
        vector<string> rst;
        int t = 0, i = 0, len = s.size();
        while(i < 9)
            t = t << 3 | s[i++] & 7;
        while(i < len)
            if(mp[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
                rst.push_back(s.substr(i - 10, 10));
        return rst;
    }
};
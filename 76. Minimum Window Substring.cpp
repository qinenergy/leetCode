class Solution2 {
public:
    string minWindow(string s, string t) {
        int sLen = s.size(), tLen = t.size();
        if(sLen < tLen || tLen == 0) return "";
        vector<int> hash(256, 0);
        for(auto& ch : t)   ++hash[static_cast<int>(ch)];
        int minLen = INT_MAX, start = 0, minStart = 0, i = 0, found = 0;
        while(i <= sLen && start < sLen){
            if(found < tLen){
                if(i == sLen)   break;
                --hash[s[i]];
                if(hash[s[i++]] >= 0) ++found;
            }
            else{
                if(i - start < minLen){
                    minLen = i - start;
                    minStart = start;
                }
                hash[s[start]]++;
                if(hash[s[start++]] > 0)    --found;
            }
        }
        return minLen <= sLen ? s.substr(minStart, minLen) : "";
    }
};
class Solution2 {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0)    return "";
        string rst = {s[0]};
        int max_len = 1;
        for(int i = 0; i < len; ++i){
            int j = i, k = i, l;
            while(k < len && s[k + 1] == s[k]) ++k;
            while(j >= 1 && k < len - 1 && s[j - 1] == s[k + 1]){
                --j;
                ++k;
            }
            l = k - j + 1;
            if(l > max_len){
                rst = s.substr(j, l);
                max_len = l;
            }
        }
        return rst;
    }
};
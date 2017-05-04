class Solution {

public:

    bool isSubsequence(string s, string t) {

        int s_p=0, t_p=0;

        int s_len=s.length(), t_len=t.length();

        while(s_p<s_len && t_p<t_len){

            if(s[s_p]== t[t_p]){

                s_p++;

                t_p++;

            }

            else

                t_p++;

        }

        return s_p==s_len;

    }

};

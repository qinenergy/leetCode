class Solution(object):

    def isSubsequence(self, s, t):

        """

        :type s: str

        :type t: str

        :rtype: bool

        """

        s_len, t_len= len(s), len(t)

        s_p, t_p = 0, 0

        while(s_p<s_len and t_p<t_len):

            if(s[s_p]==t[t_p]):

                s_p += 1

                t_p += 1

            else:

                t_p += 1

        return s_p == s_len

        

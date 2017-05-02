class Solution(object):

    def minWindow(self, s, t):

        """

        :type s: str

        :type t: str

        :rtype: str

        """

        start, end, left = 0, 0, 0

        min_len = sys.maxsize

        hash = collections.defaultdict(int)

        for i in t:

            hash[i] += 1

        num = len(t)

        for i, x in enumerate(s):

            if(hash[x]>0):

                num -= 1

            hash[x] -= 1

            while(num==0):

                if (i-left +1) < min_len:

                    start = left

                    min_len = i - left + 1

                if hash[s[left]]==0:

                    num += 1

                hash[s[left]]+=1

                left += 1

        if min_len== sys.maxsize:

            return ""

        else:

            return s[start:start+min_len]

        

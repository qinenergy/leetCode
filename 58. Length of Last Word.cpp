class Solution {
public:
	int lengthOfLastWord(string s) {
		int last = s.size() - 1;
		if (last == -1)	return 0;
		while (last >= 0 && s[last] == ' ')
			--last;
		int j = last;
		for (j = last; j >= 0; --j)
			if (s[j] == ' ') break;
		return last - j;
	}
}
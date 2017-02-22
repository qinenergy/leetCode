class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
		string prefix, pre, pos;
		if (size == 0)	return prefix;
		if (size == 1)	return strs.front();
		int i = 1, j = 0, l1 = 0, l2 = 0, l = 0;
		pre = strs.front();
		do
		{
			pos = strs[i];
			l1 = pre.size();
			l2 = pos.size();
			l = l1 <= l2 ? l1 : l2;
			for (j = 0; j < l; ++j)
			{
				if (pre[j] == pos[j])
					prefix += pre[j];
				else
					break;
			}
			++i;
			pre = prefix;
			prefix.clear();
		} while (i < size && pre.size() != 0);
		return pre;
    }
};
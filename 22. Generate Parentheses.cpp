class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> rst;
		if (n <= 0)	return rst;
		string str = "(";
		gen(rst, str, n - 1, n);
		return rst;
	}
	void gen(vector<string>& rst, string& str, int lcnt, int rcnt) {
		if (lcnt == 0 && rcnt == 0)
			rst.push_back(str);
		auto p = str.back();
		if ((p == ')' && lcnt < rcnt) || (p == '(' && rcnt > 0)) {
			str.push_back(')');
			--rcnt;
			gen(rst, str, lcnt, rcnt);
			++rcnt;
			str.pop_back();
		}
		if ((p == ')' && lcnt > 0) || (p == '(' && lcnt > 0)) {
			str.push_back('(');
			--lcnt;
			gen(rst, str, lcnt, rcnt);
			++lcnt;
			str.pop_back();
		}
	}
};
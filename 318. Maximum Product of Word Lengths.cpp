class Solution2 {
public:
    int maxProduct(vector<string>& words) {
		vector<int> m = vector<int>();
		for (auto& word : words)
			m.push_back(hashing(word));
		int product = 0;
		for (int i = 0; i < words.size(); ++i)
			for (int j = i + 1; j < words.size(); ++j)
				product = max(product, (((m[i] & m[j]) == 0)*(int)words[i].size()*(int)words[j].size()));
		return product;
	}
	int hashing(string& word) {
		int code = 0;
		int one = 1;
		for (auto& ch : word)
			code = code | (one << (ch - 'a'));
		return code;
	}
};
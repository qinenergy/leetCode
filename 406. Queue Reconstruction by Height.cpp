class Solution2 {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& A, const pair<int, int>& B) {
			return A.first > B.first || (A.first == B.first && A.second < B.second);
		};
		sort(people.begin(), people.end(), comp);
		list<pair<int, int>> ls;
		for (auto& p : people) {
			auto it = ls.begin();
			advance(it, p.second);
			ls.insert(it, p);
		}
		return vector<pair<int, int>>(ls.begin(), ls.end());
	}
};
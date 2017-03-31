class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto& word : wordDict)  set.insert(word);
        if(set.find(s) != set.end())    return true;
        vector<int> dp(1, 0);
        for(int i = 1; i <= s.size(); ++i){
            for(auto it = dp.rbegin(); it != dp.rend(); ++it){
                auto sub = s.substr(*it, i - *it);
                if(set.find(sub) != set.end()){
                    dp.push_back(i);
                    break;
                }
            }
        }
        return dp.back() == s.size();
    }
};
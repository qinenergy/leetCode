class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> rest(wordList.begin(), wordList.end()), beginList, endList;
        if (rest.find(endWord) != rest.end())   rest.erase(endWord);
        else    return 0;
        int len = 2;
        beginList.insert(beginWord);
        endList.insert(endWord);
        while(!beginList.empty() && !endList.empty()){
            unordered_set<string>* pb;
            unordered_set<string>* pe;
            beginList.size() < endList.size() ? pb = &beginList, pe = &endList : pb = &endList, pe = &beginList; 
            unordered_set<string> tmp;
            for(auto it = pb->begin(); it!=pb->end(); it++){
                string& w = *it;
                for(int i = 0; i < w.size(); i++){
                    char c = w[i];
                    for(int j = 0; j < 26; j++){
                        w[i] = 'a'+j;
                        if (w[i] == c) continue;
                        if (pe->find(w) != pe->end())
                            return len;
                        if (rest.find(w) != rest.end()) {
                            tmp.insert(w);
                            rest.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            ++len;
            *pb = tmp;
        }
        return 0;
    }
};
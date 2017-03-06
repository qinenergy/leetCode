class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	int len = strs.size();
    	if(len <= 1)	return {strs};
    	vector<vector<string>> rst;
    	map<string, int> wordmap;	
    	for(auto& word : strs){
    		string key = word;
    		sort(key.begin(), key.end());
    		auto it = wordmap.find(key);
    		if(it == wordmap.end()){
    			wordmap.insert({key, rst.size()});
    			rst.push_back({word});
    		}
    		else rst[it->second].push_back(word);
    	}
    	return rst;
    }
};
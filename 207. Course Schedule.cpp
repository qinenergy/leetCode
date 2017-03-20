class Solution2 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	if(numCourses <= 0)	return false;
    	vector<int> required(numCourses, 0);
    	for(int c = 0; c < numCourses; ++c)
    		if(!dfs(prerequisites, required, c))
    			return false;
		return true;
    }

    bool dfs(vector<pair<int, int>>& prerequisites, vector<int>& required, int course){
    	if(required[course] == -1)	return false;
    	if(required[course] == 1)	return true;
    	required[course] = -1;
    	for(auto& reqPair : prerequisites){
    		if(reqPair.first == course){
    			int req = reqPair.second;
    			if(required[req] == -1)
    				return false;
    			auto res = dfs(prerequisites, required, req);
    			if(!res)	return false;
    		}
    	}
    	required[course] = 1;
    	return true;
    }
};
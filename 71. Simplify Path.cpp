class Solution2 {
public:
    string simplifyPath(string path) {
    	int len = path.size();
    	if(len == 0)	return "";
    	deque<string> dq;
    	int i = 0, j = 1, cnt_dot = 0;
    	while(j < len){
    		if(path[i] != '/') throw new runtime_error("invalid input");
    		while(j < len && path[j] == '/'){
    			++i;
    			++j;
    		}
    		if(j == len){
    			if(i < j - 1)
    				dq.push_back(string(path.begin() + i, path.begin() + j));
    			break;
    		}
    		cnt_dot = 0;
    		while(j < len && path[j] == '.'){
    			++cnt_dot;
    			++j;
    		}
            if(cnt_dot == 2 && (j == len || path[j]=='/'))
    			if(!dq.empty())
    				dq.pop_back();
    		else{
    		    if(cnt_dot != 1){
    			    while(j < len && path[j] != '/')
    				    ++j;
    			    dq.push_back(string(path, i, j - i));
    		    }
    		}
    		i = j;
    		j = i + 1;
    	}
    	string rst;
    	while(!dq.empty()){
    		rst.append(dq.front(), 0, dq.front().size());
    		dq.pop_front();
    	}
    	return rst.empty() ? "/" : rst;
    }
};
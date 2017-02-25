class Solution2 {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total(0), last(-1), end;
        for(auto& val : timeSeries){
        	end = max(duration - last + val -1, 0) + last;
        	last >= val ? total += (end - last) : total += (end - val + 1);
        	last = end;
        }
        return total;
    }
};

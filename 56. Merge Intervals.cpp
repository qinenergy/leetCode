class Solution2 {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len <= 1)	return intervals;
        vector<Interval> rst;
        auto compare = [](const Interval& a, const Interval& b){ return a.start < b.start; };
        sort(intervals.begin(), intervals.end(), compare);
        int i = 0;
        while(i < len){
        	rst.push_back(intervals[i]);
        	int j = i + 1;
        	while(j < len && intervals[j].start <= rst.back().end)
        		rst.back().end = max(rst.back().end, intervals[j++].end);
        	i = j;
        }
        return rst;
    }
};
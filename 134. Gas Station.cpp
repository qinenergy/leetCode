class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num = gas.size();
        if(num != cost.size() || num <= 0)  return -1;
        int rest = 0, total = 0, start = -1;
        for(int i = 0; i < num; ++i){
            rest += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if(rest >= 0 && start == -1)
                start = i;
            else if(rest < 0){
                rest = 0;
                start = -1;
            }
        }
        if(total < 0)   return -1;
        return start;
    }
};
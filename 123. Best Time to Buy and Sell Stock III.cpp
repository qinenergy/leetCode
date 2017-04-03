class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int hold1(INT_MIN), hold2(INT_MIN), sell1(0), sell2(0);
        for(auto& val : prices){
            sell2 = max(sell2, hold2 + val);
            hold2 = max(hold2, sell1 - val);
            sell1 = max(sell1, hold1 + val);
            hold1 = max(hold1, - val);
        }
        return sell2;
    }
};
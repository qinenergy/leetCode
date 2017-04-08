class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int num = prices.size(), profit = 0;
        if(num <= 1)    return 0;
        for(int i = 0; i < num - 1; ++i)
            if(prices[i] < prices[i + 1])   profit += (prices[i + 1] - prices[i]);
        return profit;
    }
};
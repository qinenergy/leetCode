class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
	if (prices.empty())
			return 0;
		int N = prices.size();
		int minPrice = prices[0], profit = 0;
		for (int i = 0; i < N; i++)
		{
			minPrice = std::min(prices[i], minPrice);
			profit = std::max(prices[i] - minPrice, profit);
		}
		return profit;
	}
};
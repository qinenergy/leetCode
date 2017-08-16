class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> amounts(amount + 1, INT_MAX);
        amounts[0] = 0;
        for(int a = 1; a <= amount; ++a){
            for(int c = 0; c < coins.size(); ++c){
                if(coins[c] > a) continue;
                amounts[a] = std::min(amounts[a - coins[c]] + 1, amounts[a]);
            }
            for(auto v : amounts) cout << v << " ";
            cout << endl;
        }
        return amounts[amount] >= INT_MAX ? -1 : amounts[amount];
    }
};

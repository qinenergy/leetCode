class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        for(int i=0; i<ratings.size()-1; i++){
            if(ratings[i+1]>ratings[i]) candy[i+1] = candy[i] + 1;
        }
        for(int i=ratings.size()-1; i>0; i--)
            if(ratings[i-1]>ratings[i]) candy[i-1] = max(candy[i-1], candy[i]+1);
        return accumulate(candy.begin(),candy.end(), 0);
    }
};

class Solution2 {
public:
    int candy(vector<int>& ratings) {
        int num = ratings.size();
        if(num <= 1)    return num;
        vector<int> candies(num, 1);
        for(int i = 1; i < num; ++i)
            if(ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        for(int i = num - 2; i >= 0; --i)
            if(ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
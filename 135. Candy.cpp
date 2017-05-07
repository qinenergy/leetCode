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
    /*
     *  o(N) time & o(N) space
     *  int candy(vector<int>& ratings) {
     *      int num = ratings.size();
     *      if(num <= 1)    return num;
     *      vector<int> candies(num, 1);
     *      for(int i = 1; i < num; ++i)
     *          if(ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
     *      for(int i = num - 2; i >= 0; --i)
     *          if(ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
     *      return accumulate(candies.begin(), candies.end(), 0);
     *  }
     */

     // o(N) time & o(1) space
     int candy(vector<int>& ratings) {
        int num = ratings.size();
        if(num <= 1)    return num;
        int total = 1, prev = 1, count = 0;
        for(int i = 1; i < num; ++i){
            if(ratings[i] >= ratings[i - 1]){
                if(count > 0){
                    total += (count * (count + 1) / 2);
                    if(count >= prev)   total += count - prev + 1;
                    count = 0;
                    prev = 1;
                }   
                prev = (ratings[i] == ratings[i - 1]) ? 1 : prev + 1;
                total += prev;
            }
            else ++count;
        }
        if(count > 0){
            total += (count * (count + 1) / 2);
            if(count >= prev)   total += count - prev + 1;
        }
        return total;
     }
};
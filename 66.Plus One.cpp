class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int plus = 1;
        int digit = 0;
        for(int i = digits.size()-1; i>=0; i--){
            digit = digits[i] + plus;
            if(digit==10){
                plus = 1;
                res.push_back(0);
            }
            else{
                plus = 0;
                res.push_back(digit); 
            }
        }
        if(plus==1) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};

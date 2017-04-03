class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> rst;
        vector<string> solution;
        partitionPalindrome(s, 0, s.size(), rst, solution);
        return rst;
    }
    void partitionPalindrome(string& s, int ind, int len, vector<vector<string>>& rst, vector<string>& solution){
        if(ind == len){
            rst.push_back(solution);
            return;
        }
        for(int i = ind; i < len; ++i){
            if(isPalindrome(s, ind, i)){
                solution.push_back(s.substr(ind, i - ind + 1));
                partitionPalindrome(s, i + 1, len, rst, solution);
                solution.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end){
        while(start <= end)
            if(s[start++] != s[end--])
                return false;
        return true;
    }
};
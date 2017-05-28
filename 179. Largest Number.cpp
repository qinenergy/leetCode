class Solution2 {
public:
    static bool biggerThan(string& num1, string& num2){
        string s1 = num1 + num2;
        string s2 = num2 + num1;
        return s1 > s2;
    }
    string largestNumber(vector<int>& nums) {
       int len = nums.size();
       vector<string> str_nums;
       bool all_zero = true;
       for(const auto& num : nums){
           str_nums.push_back(to_string(num));
           all_zero = all_zero && (num == 0);
       }
       if(all_zero) return "0";
       sort(str_nums.begin(), str_nums.end(), biggerThan);
       string rst = "";
       for(const auto& str_num : str_nums) rst += str_num;
       if(rst.empty()) return 0;
       return rst;
   }
;

class Solution2 {
public:
    string largestNumber(vector<int>& nums) {
       int len = nums.size();
       vector<string> str_nums;
       bool all_zero = true;
       for(const auto& num : nums){
           str_nums.push_back(to_string(num));
           all_zero = all_zero && (num == 0);
       }
       if(all_zero) return "0";
       sort(str_nums.begin(), str_nums.end(),
            [](const string& s1, const string& s2){ return s1 + s2 > s2 + s1; });
       string rst = "";
       for(const auto& str_num : str_nums) rst += str_num;
       if(rst.empty()) return 0;
       return rst;
   }
};

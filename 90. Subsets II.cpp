class Solution2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	int len = nums.size();    
    	vector<vector<int>> rst = {{}};
    	sort(nums.begin(), nums.end());
    	vector<int> comb;
    	subset(rst, comb, nums, 0, len);
    	return rst;
    }

    void subset(vector<vector<int>>& rst, vector<int>& comb, vector<int>& nums, int s, int len){
    	if(s == len) return;
    	int i = s, j;
    	while(i < len){
    		comb.push_back(nums[i]);
    		rst.push_back(comb);
    		subset(rst, comb, nums, i + 1, len);
    		comb.pop_back();
    		++i;
    		while(i < len && nums[i] == nums[i - 1]) ++i;
    	}
    }
};
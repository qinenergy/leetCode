class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	int len = nums.size();
    	vector<vector<int>> rst {vector<int>({})};
    	vector<int> sub;
    	subsets(rst, sub, nums, 0, len);
    	returnr rst;
    }
    void subsets(vector<vector<int>>& rst, vector<int>& sub, vector<int>& nums, int start, int len){
    	if(start == len)	return;
    	while(start < len){
    		sub.push_back(nums[start]);
    		rst.push_back(sub);
    		subsets(rst, sub, nums, start + 1, len);
    		sub.pop_back();
    		++start;
    	}
    }
};
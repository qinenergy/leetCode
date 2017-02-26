class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> rst;  
    	if(nums.size() == 0)	return rst;
    	_permute(rst, nums, 0);
    	return rst;
    }
    void _permute(vector<vector<int>>& rst, vector<int>& nums, int start){
    	if (start == nums.size())
    		rst.push_back(nums);
    	for(int i = start; i < nums.size(); ++i){
    		swap(nums[start], nums[i]);
    		_permute(rst, nums, start + 1);
    		swap(nums[start], nums[i]);
    	}
    }
};
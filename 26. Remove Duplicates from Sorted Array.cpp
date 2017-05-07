class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int j = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[j]) nums[++j] = nums[i];
        }
        return j+1;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)	return 0;
		if (nums.size() == 1)	return 1;
		int idx0(0), idx1(1);
		for (; idx1 < nums.size(); ++idx1)
		{
			if (nums[idx1] != nums[idx0])
				nums[++idx0] = nums[idx1];
		}
		return idx0 + 1;

    }
};
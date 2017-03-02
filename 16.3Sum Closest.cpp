class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=0;
        if(nums.size()<3) return -1;
        sort(nums.begin(), nums.end());
        int min_distance = INT_MAX;
        int j,k, distance;
        for(int i=0; i<nums.size()-2; i++){
            j = i + 1;
            k = nums.size() - 1;
            while(j<k){
                distance = target - nums[i] - nums[j] - nums[k];
                if(abs(distance) < min_distance){
                    min_distance = abs(distance);
                    res = nums[i] + nums[j] + nums[k];
                }
                if(distance<0)
                    k--;
                else if (distance>0)
                    j++;
                else
                    return res;
            }
        }
        return res;
    }
};

class Solution2 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int rst, sum, diff, minDiff = INT_MAX;
		int len = nums.size();
		if(len < 3)	throw new runtime_error("invalid");
		sort(nums.begin(), nums.end());
		int start = 0, mid = 1, end = len - 1;
		for(start = 0; start < len - 2; ++start){
			mid = start + 1;
			end = len - 1;
			while(mid < end){
				sum = nums[start] + nums[mid] + nums[end];
				diff = sum - target;
				if(minDiff > abs(diff)){
					minDiff = abs(diff);
					rst = sum;
				}
				if(diff == 0)	return rst;
				else if(diff > 0)	--end;
				else	++mid;
			}
		}
		return rst;
	}	
};


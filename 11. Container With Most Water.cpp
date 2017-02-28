class Solution2 {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;
		int area = -1;
		while(i < j){
			area = max(area, min(height[i], height[j]) * (j - i));
			height[i] < height[j] ? ++i : --j;
		}
		return area;
	}
};
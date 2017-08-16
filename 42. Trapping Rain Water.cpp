class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        for(int i=1; i<n; i++)
            left_max[i] = max(left_max[i-1], height[i-1]);
        for(int i=n-2; i>=0; i--)
            right_max[i] = max(right_max[i+1], height[i+1]);
        int ans = 0;
        for(int i=0; i<n; i++){
            int sr = min(left_max[i], right_max[i]);
            if(sr > height[i])
                ans += sr - height[i];
        }
        return ans;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len <= 2)    return 0;
        vector<int> L(len, INT_MIN), R(len, INT_MIN);
        int trapped = 0;
        for(int i = 1; i < len; ++i){
            L[i] = max(L[i - 1], height[i - 1]);
            R[len - i - 1] = max(R[len - i], height[len - i]);
        }
        for(int i = 1; i < len - 1; ++i)
            trapped += min(max(L[i] - height[i], 0), max(R[i] - height[i], 0));
        return trapped;
    }
};
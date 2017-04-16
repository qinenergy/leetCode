class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int preProduct = 1, postProduct = 1;
        int rst = INT_MIN;
        int len = nums.size();
        for(int i = 0; i < len; ++i){
            preProduct *= nums[i];
            postProduct * = nums[len - i - 1];
            rst = max(rst, max(preProduct, postProduct));
            preProduct == 0 ? preProduct = 1 : preProduct = preProduct;
            postProduct == 0 ? postProduct = 1 : postProduct = postProduct;
        }
        return rst;
    }
};
class NumArray2 {
public:
    NumArray(vector<int> nums) {
        _len = nums.size();
        _acc = vector<int>(_len + 1, 0);
        for(int i = 0; i < _len; ++i)
            _acc[i + 1] = _acc[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        if(i > j || i >= _len || j >= _len || i < 0 || j < 0)
            throw new runtime_error("invalid i and j");
        return _acc[j + 1] - _acc[i];
    }
private:
    vector<int> _acc;
    int _len;
};
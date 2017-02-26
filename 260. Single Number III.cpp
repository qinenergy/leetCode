class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() < 2)	throw new runtime_error("invalid");
		int _xor = 0;
		for (auto& val : nums)
			_xor = _xor ^ val;
		_xor = _xor & ~(_xor & (_xor - 1));
		int num1 = 0, num2 = 0;
		for (auto& val : nums) {
			if ((_xor & val) == _xor)
				num1 = num1 ^ val;
			else
				num2 = num2 ^ val;
		}
		return vector<int>({num1, num2});
    }
};
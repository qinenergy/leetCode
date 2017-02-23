class Solution1 {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i=1; i<=num; i++){
            res[i] = res[i&(i-1)]+1;
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> countBits(int num) {
        vector<int> rst(num + 1, 0);
		int base = 1;
		while (base <= num) {
			for (int i = base; i < base + base && i <= num; ++i)
				rst[i] = rst[i - base] + 1;
			base = (base << 1);
		}
		return rst;
    }
};

class Solution1 {
public:
    int reverse(int x) {
        long long y = 0;
        int absx = abs(x);
        while (absx>0){
            y = 10*y + absx%10;
            absx /= 10;
        }
        if(x<0) y = -y;
        if(y<INT_MIN || y>INT_MAX)
            return 0;
        else
            return (int)y;
    }
};

class Solution2 {
public:
    int reverse(int x) {
    	long returnInt = 0;
		while (x)
		{
			returnInt = returnInt * 10 + x % 10;
			x /= 10;
		}
		if (returnInt>0)
			return returnInt > INT_MAX ? 0 : returnInt;
		else return returnInt < INT_MIN ? 0 : returnInt;
    }
};

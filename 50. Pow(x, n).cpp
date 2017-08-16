class Solution2 {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;
        unsigned int p = n;
        if(n < 0){
            x = 1 / x;
            p = -n;
        }
        double power = 1;
        while(p){
            if(p & 1)
                power *= x;
            x *= x;
            p >>= 1;
        }
        return power;
    }
};
class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0)   return false;
        int y = 0, n = x;
        while(x){
            y = 10 * y + x % 10;
            x /= 10;
        }
        if(y == n)  return true;
        return false;
    }
};
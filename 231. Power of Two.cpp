class Solution {
public:
/*
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        
        int onebitcount = 0;      
        for(int i=0; i<32; i++){
            if ((n&1)==1){
                onebitcount++;
            }
            n = n >> 1;
        }
        return onebitcount ==1;
    }
    */
    bool isPowerOfTwo(int n) {
        return n>0 && ((n & (n-1))==0);
    }
};
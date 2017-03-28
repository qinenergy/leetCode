class Solution2 {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
         if(maxChoosableInteger >= desiredTotal)    return true;
         if((maxChoosableInteger * (maxChoosableInteger + 1)) / 2 < desiredTotal)   return false;
         unordered_map<int, bool> m;
         unsigned int used = 0;
         return canIWin(m, used, maxChoosableInteger, desiredTotal);
    }
    bool canIWin(unordered_map<int, bool>& m, unsigned int& used, int maxChoosableInteger, int desiredTotal){
        if(desiredTotal <= 0)   return false;
        if(m.find(used) != m.end())    return m[used];
        unsigned int old = used;
        for(int i = 1; i <= maxChoosableInteger; ++i){
            if(!((1 << i) & used)){
                used |= (1 << i);
                if(!canIWin(m, used, maxChoosableInteger, desiredTotal - i)){
                    m[old] = true;
                    used = old;
                    return true;
                }
                used = old;
            }
        }
        m[old] = false;
        return false;
    }
};
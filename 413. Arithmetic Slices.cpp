class Solution1 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n<3) return 0;
        vector<int> mark(n, 0);
        for(int i=2; i<n; i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
                mark[i] = mark[i-1]+1;
        }
        return accumulate(mark.begin(),mark.end(),0);
    }
};

class Solution2 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len <= 2)	return 0;
        int count = 0, delta = 0, start = 0, end = 2, L = 0;
        while(start < len - 2) {
        	delta = A[start + 1] - A[start];
        	while(end < len && (A[end] - A[end - 1] == delta))	++end;
        	L = end - start;
        	if(L > 2)
        		count += (L - 1)*(L - 2) / 2;
        	start = end - 1;
        	++end;
        }
        return count;
    }
};


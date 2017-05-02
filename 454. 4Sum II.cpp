class Solution {

public:

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int, int> hash;

        int cnt = 0;

        if(A.size() * B.size() * C.size() * D.size()==0) return cnt;

        for(int i=0; i< A.size(); i++){

            for(int j=0; j<B.size(); j++){

                hash[A[i]+B[j]]++;

            }

        }

        for(int i=0; i< C.size(); i++){

            for(int j=0; j<D.size(); j++){

                cnt += hash[-C[i]-D[j]];

            }

        }

        return cnt;

    }

};

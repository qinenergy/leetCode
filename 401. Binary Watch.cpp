class Solution {

public:

    vector<string> readBinaryWatch(int num) {

        vector<string> res;

        for(int i=0;i<1024;i++){

            if(bitset<10>(i).count()==num){

                int h = i>>6;

                int m = i & 0b0000111111;

                if(h<12 && m<60)

                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));

            }

        }

        return res;

    }

};

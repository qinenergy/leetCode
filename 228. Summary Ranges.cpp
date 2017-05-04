class Solution {

public:

    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;

        int n = nums.size();

        if(n==0) return ans;

        int l=INT_MIN, r=INT_MAX;

        bool start=false;

        for(int i=0; i<n; i++){

            if(not start){

                l=nums[i];

                r=nums[i];

                start = true;

            }

            else if(nums[i]==r+1){

                r=nums[i];  

            }

            else{

                if(r>l)

                    ans.push_back(to_string(l)+"->"+to_string(r));

                else

                    ans.push_back(to_string(l));

                l=nums[i];

                r=nums[i];

            }

        }

        if(r>l)

            ans.push_back(to_string(l)+"->"+to_string(r));

        else

            ans.push_back(to_string(l));

        return ans;

    }

};

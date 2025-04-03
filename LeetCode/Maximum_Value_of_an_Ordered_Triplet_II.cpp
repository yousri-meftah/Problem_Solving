class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long maxel = 0;
            long long maxdiff = 0 ;
            long long maxmul = 0;
            
            for(auto i:nums){
                maxmul = max(maxmul , maxdiff*i);
                maxdiff = max(maxdiff , maxel - i );
                maxel = max(maxel ,(long long) i);
            }
            return maxmul;
    
        }
    };
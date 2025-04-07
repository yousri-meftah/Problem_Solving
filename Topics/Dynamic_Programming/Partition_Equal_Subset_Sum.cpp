class Solution {
    public:
    int dp[201][20001];
    
        bool rec(int pos , int have , int left, vector<int> &nums){
            if(left == have) return true;
            if(pos == nums.size())return false;
            if(dp[pos][have]!=-1)return dp[pos][have];
            return dp[pos][have] = rec(pos+1,have+nums[pos] , left - nums[pos] , nums)||rec(pos+1,have,left,nums);
        }
        bool canPartition(vector<int>& nums) {
            int sum = 0 ;
            for(auto i:nums)sum+=i;
            memset(dp,-1,sizeof dp);
            return rec(0,0,sum,nums);
        }
    };
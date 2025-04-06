class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int n  = nums.size();
            vector<int> dp(n,1);
            vector<int> pos(n,-1);
            for(int i = n-1 ;i>=0;i--){
                for(int j = i+1 ; j<n;j++){
                    if(nums[j]%nums[i]==0)
                        if(dp[i]<(dp[j]+1))
                            dp[i] = max(dp[i] , dp[j] + 1 ),pos[i] = j;
                }
            }  
            int ans_pos =0;
            int pp = 0 ;
            int ma = 0;
            for(auto i:dp)
            {
                if(i>ma){
                    ma = i;
                    ans_pos = pp;
                }
                pp++;
            }
            vector<int> ans;
            ans.push_back(nums[ans_pos]);
            while(pos[ans_pos]!=-1){
                ans.push_back(nums[pos[ans_pos]]);
                ans_pos = pos[ans_pos];
            }
            return ans;
        }
    };
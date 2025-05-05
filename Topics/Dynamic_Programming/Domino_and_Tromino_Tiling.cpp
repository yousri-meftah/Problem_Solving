class Solution {
    public:
        int MA = 1e9+7;
        int dp[1005][2];
        long long rec(int n ,int ok ){
            if(ok&&n==1)return 0;
            if(n==1)return 1;
            if(n==0)return 1;
            if(n==2&&ok)return 1;
            if(n==2) return 2 ; 
            if(dp[n][ok]){
                return dp[n][ok] % MA;
            }
            if(ok){
                return dp[n][ok] = rec(n-2,0) + rec(n-1,ok)% MA;
            }
            return dp[n][ok] = (rec(n-1,0)+ rec(n-1,1)+rec(n-1,1)  + rec(n-2,0))% MA;
        }
        int numTilings(int n) {
            return rec(n, 0)% MA;
        }
    };
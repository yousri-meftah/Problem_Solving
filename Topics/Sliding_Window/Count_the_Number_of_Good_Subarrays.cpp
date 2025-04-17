class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            long long ans = 0;
            int l = 0 , r =0;
            map<int,int> mp;
            int nb = 0;
            int n = nums.size();
            while(r<n){
                if(mp[nums[r]])nb+=mp[nums[r]];
                mp[nums[r]]++;
                if(nb>=k){
                    int cnt  = 0;
                    int left = n - r;
                    while(nb>=k&&r>l){
                        mp[nums[l]]--;
                        nb-=mp[nums[l]];
                        cnt++;
                        l++;
                    }
                    ans+=(cnt*left);
                }
                r++;
            }
            return ans;
            
        }
    };
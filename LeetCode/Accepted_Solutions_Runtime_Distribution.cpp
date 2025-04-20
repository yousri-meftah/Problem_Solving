class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(),nums.end());
            long long ans = 0 ;
            int n = nums.size();
            for(int i = 0 ;i<n;i++){
                int l = lower_bound(nums.begin(), nums.end(), lower-nums[i])-nums.begin();
                int r = upper_bound(nums.begin(), nums.end(), upper-nums[i])-nums.begin();
                //cout<<" l = "<<l<<" r = "<<r<<endl;
                ans+=r-l;
                if(i>=l&&i<r)ans--;
            }
            //cout<<"ans = "<<ans;
            return ans/2;
        }
    };
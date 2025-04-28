class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long ans = 0;
            int l = 0;
            long long sum = 0;
            int nb = 0;
            int n = nums.size();
            for(int r=0;r<n;r++){
                sum+=nums[r];
                nb++;
                long long u = sum*nb;
                while(l<=r&&u>=k){
                    sum-=nums[l];
                    nb--;
                    u = sum*nb;
                    l++;
                }
                ans+=(r-l+1);
            }
            return ans;
        }
    };
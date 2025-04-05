class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size();
            int t = 1<<n;
            int ans = 0 ;
            for(int i =1;i<t;i++){
                int s = 0 , pos = 0 , bit = 1;
                while(bit<=i){
                    if((i&bit)!=0)
                        s^=nums[pos];
                    bit*=2;
                    pos++;
                }
                ans+=s;
            }
            return ans;
        }
    };
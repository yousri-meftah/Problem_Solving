class Solution {
    public:
        int f(int pos , int s , vector<int> &nums){
            if(pos==nums.size())return s;
            return f(pos+1,s,nums) + f(pos+1,s^nums[pos],nums);
        }
        int subsetXORSum(vector<int>& nums) {
            return f(0,0,nums);
        }
    };
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        sort(arr.begin(),arr.end());
        int should_be = 1 ; 
        int pos = 0;
        for(auto i:arr){
             
            res[pos] = min(i , should_be);
            if(should_be<=i){   
                should_be++;
            }
            pos++;
        }
        return res[n-1];
    }
};
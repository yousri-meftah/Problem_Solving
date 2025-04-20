class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            map<int,int> mp;
            int ans=  0;
            for(auto i:answers)if(i)mp[i]++;else ans++;
            for(auto i:mp){
                int y = i.second;
                int u = (y / (i.first+1)) * (i.first+1) ; 
                int t = (y%(i.first+1)!=0) *  (i.first+1); 
                ans+=u+t;
            }
            return ans;
        }
    };
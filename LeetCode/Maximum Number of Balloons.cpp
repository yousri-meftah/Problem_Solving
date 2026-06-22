class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<int,int> mp;
        for(auto i:text)mp[i]++;
        string ch = "balloon";
        int ans = 1e9 ;
        for(auto i:ch){
            if(i=='l'||i=='o') ans = min(ans , mp[i]/2);
            else ans = min(ans , mp[i] );
        }
        return ans;
    }
};
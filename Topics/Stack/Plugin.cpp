#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod  = 1e9+7;


void solve() {
    string ch;
    cin>>ch;
    int n = ch.size();
    string s = "";
    for(auto i:ch){
        if(!s.size()){
            s+=i;
        }else{
            if(s[s.size()-1]==i){
                s.pop_back();
            }else{
                s+=i;
            }
        }
    }
    cout<<s<<endl;
    
}

int32_t main() {
    FAST;
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
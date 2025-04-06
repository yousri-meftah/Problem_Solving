#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod  = 1e9+7;


void solve() {
    string ch;
    cin>>ch;
    int n = ch.size();
    int nb = 0;
    int l = 0;
    int ans = 0 ;
    int r = 0;
    stack<char> st;
    for(auto i:ch){
        if(i=='(')
            st.push(i);
        else if(i==')'){
            if(st.size()){
                st.pop();
                ans+=2;
            }
    }
}
    cout<<ans<<endl;

    
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
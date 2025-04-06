#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod  = 1e9+7;


void solve() {
    string ch;
    cin>>ch;
    int n = ch.size();
    bool state = false;
    bool ok = true;
    while(ok){
        int pos = 0;
        bool find = false;
        for(int i = 0 ; i<n-1;i++){
            if(ch[i]==ch[i+1]){
                find = true;
                pos = i;
                break;
            }
        }
        if(find){
            ch.erase(pos, 2);
            n -= 2;
        } else break;
        state = !state;
    }
    if(!state)cout<<"No\n";
    else cout<<"Yes\n";
    
    
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
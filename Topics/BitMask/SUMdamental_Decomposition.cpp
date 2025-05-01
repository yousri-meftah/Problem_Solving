#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;


void solve() {
    ll n, x; cin >> n >> x;
    if(n == 1) {
        if(x == 0) cout << -1 << endl;
        else cout << x << endl;
        return;
    }

    int cntV = 0;
    for(int i = 0; i <= 32; i++) {
        if((1ll << i) & x) {
            cntV++;
        }
    }
    if(cntV >= n) {
        cout << x << endl;
        return;
    } 

    ll ans = x; bool active = x&1;
    int i = n - cntV; 
    if(i&1) {
        if( (!cntV) || (cntV == 1 && active)) {
            ans += (i+3);
        } else ans += (i+1);
    } else {
        ans += i;
    }
    cout << ans << endl;
}


int main() {
    fast;
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
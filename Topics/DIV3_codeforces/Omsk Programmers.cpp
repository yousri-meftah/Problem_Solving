#include <bits/stdc++.h>
using namespace std;




void solve() {
    int a ,b ,x;
    cin>>a>>b>>x;
    int ans = 1e9;
    int diff = abs(a-b);
    ans = diff;
    int ma = max(a,b);
    int mi = min(a,b);
    int nb = 1;
    while((ma>0||mi>0)){
        ma = ma / x;
        int diff = abs(ma-mi);
        ans = min(ans , diff + nb );
        if (ma < mi) swap(ma, mi);
        nb++;
    }
    cout<<ans<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
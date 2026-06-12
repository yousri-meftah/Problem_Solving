#include <bits/stdc++.h>
using namespace std;




void solve() {
    int n ; 
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)cin>>i;
    int ma = 0;
    int mi = 1e9;
    for(auto i:v){
        ma=max(ma,i);
        mi = min(mi,i);
    }
    cout<<ma-mi+1<<endl;
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
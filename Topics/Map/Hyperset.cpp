#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

string generate_what_we_need(string &a , string &b , int k){
    string ans = "";
    string chh = "STE";
    for(int i=0;i<k;i++){
        if(a[i] == b[i]) ans+=a[i];
        else{
            for(auto j:chh){
                if(j!=a[i] && j!=b[i]){
                    ans+=j;
                    break;
                }
            }
        }
    }
    // cout<<" for s1 = "<<a<<" and s2 = "<<b<<" we need "<<ans<<"\n";
    return ans;
}

void solve() {
    int n , k;
    cin>>n>>k;
    vector<string> v(n);
    int ans = 0;
    map<string , int> mp;
    for(int i=0;i<n;i++) cin>>v[i],mp[v[i]]++;
    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            string ch = generate_what_we_need(v[i] , v[j] , k);
            int y = mp[ch];
            if(ch == v[i]) y--;
            if(ch == v[j]) y--;
            // cout<<" y = "<<y<<"\n";
            ans+=y;
        }
    }
    cout<<ans/3<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;




void solve() {
    int n,k ; 
    cin>>n>>k;
    string s;
    cin>>s;
    vector<bool> vis(n);
    for(int i =0;i<n;i++){
        int start= i;
        int next = i+k;
        if(next<n){
            if(s[start]=='1'){
                s[start]='0';
                if(s[next]=='1')s[next]='0';
                else s[next]='1';
            }
            start+=k;
            next+=k;
        }
    }
    bool ok =true;
    for(auto i:s)if(i=='1'){ok=false;break;}
    if(ok)cout<<"YES"<<endl;else cout<<"NO"<<endl;
    
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
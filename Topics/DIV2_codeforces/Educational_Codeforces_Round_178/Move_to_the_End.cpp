#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector


void solve() {
    int n ;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)cin>>i;
    vector<int> dp1(n+3,0); 
    vector<long long> suf(n+1,0);
    for(int i=n-1;i>=0;i--){
        suf[i] = suf[i+1]+v[i];
    }
    for(int i=0;i<n;i++){
        dp1[i+2] = max(dp1[i+1],v[i]);
    }
    //cout<<" ans = ";
    for(int i=0;i<n;i++){
        int pos = n-i-1;
        long long sum = suf[n-i-1] ;
        if(v[pos]<dp1[n-i]){
            cout<<sum+(dp1[n-i]-v[pos])<<" ";
            continue;
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}

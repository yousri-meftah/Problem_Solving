#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod  = 1e9+7;

bool check(int x , vector<int> &v , int k , int n){
    int nb = 0;
    set<int> s;
    for(auto i:v){
        if(i<x){
            s.insert(i);
            
        }
        if(s.size()==(x)){
            s.clear();
            nb++;
        }
    }
    return nb>=k;
}

void solve() {
    int n , k ;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    int ans = 0;
    int l = 0 , r = (n/k) +1 ;
    while(l<=r){
        int md = l + (r - l ) / 2;
        if(!check(md,v,k,n))r = md-1;
        else {
            ans = md;
            l = md +1;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    FAST;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
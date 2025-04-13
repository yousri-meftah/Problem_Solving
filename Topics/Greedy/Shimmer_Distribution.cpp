#include <bits/stdc++.h>
using namespace std;

void solve(){
    int  n  , m ;
    cin>>n>>m;
    int div = n/m;
    int mod = n%m;
    vector<int> ans(m,div);
    int pos = m-1;
    while(mod--){
        ans[pos]++;
        pos--;
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
    
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) { solve(); }
}
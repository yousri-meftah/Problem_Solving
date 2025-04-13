#include <bits/stdc++.h>
using namespace std;

void solve(){
    int  n  , m , k;
    cin>>n>>m>>k;
    if(n<=m&&n<=k){
        cout<<"Yes"<<"\n";
        return;
    }
    cout<<"No"<<endl;
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) { solve(); }
}
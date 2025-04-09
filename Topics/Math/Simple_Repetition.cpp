#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod  = 1e9+7;

bool prime( int x ){
    if(x==1) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3; i*i<=x; i+=2){
        if(x%i==0) return false;
    }
    return true;
}
void solve() {
    int n ,k ;
    cin>>n>>k;
    if(n==2 && k==1){
        cout<<"YES"<<endl;
        return;
    }
    if(n==1&&k==2){
        cout<<"YES"<<endl;
        return;
    }
    if(n%2==0){
        cout<<"NO"<<endl;
        return;
    }
    if(prime(n)&& k==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

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
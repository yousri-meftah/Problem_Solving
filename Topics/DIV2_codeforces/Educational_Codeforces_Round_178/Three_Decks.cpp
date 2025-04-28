#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector


void solve() {
    long long a,b,c ;
    cin >> a>>b>>c; 
    long long y = b-a;
    c-=y;
    if(c<b){
        cout << "NO" << endl;
        return;
    }
    long long t = c-b;
    if(t%3){
        cout << "NO" << endl;
        return;
    }
    cout<<"YES" << endl;
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}

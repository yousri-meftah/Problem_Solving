#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n ;
    cin>> n;
    vector<int> v(n);
    int mo = 1e9 + 7;
    for(auto &i:v){
        cin>>i;
        mo = min(mo,i);
    }
    int last = mo;
    unordered_set<int> s;
    s.insert(last);
    last+=(last%2);
    s.insert(last);
    while(last>1){
        s.insert(last);
        if(last%2==0)last/=2;
        else last++;
    }
    long long mi = LLONG_MAX;
    for(auto i : s){
        bool ok  = true;
        long long nb = 0;
        for(auto j : v){
            int y =  j ; 
            while(y>i){
                if(y%2==0)y/=2;
                else y++;
                nb++;
            }
            if(y%2&&y==i-1){
                nb++;
                y++;
            }
            if(y!=i){
                ok = false;
                break;
            }
        }
        if(ok){
            mi = min(mi,nb);
        }
    }
    cout<<mi<<"\n";
    



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
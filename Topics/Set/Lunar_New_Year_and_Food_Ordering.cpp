#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector

void solve() {
    int n, m;
    cin>>n>>m;
    vector<long long> a(n), c(n);
    for(auto &x : a) cin >> x;
    for(auto &x : c) cin >> x;
    set<pair<long long,long long>> s;
    for(int i = 0; i < n; i++){
        s.insert({c[i], i});
    }
    while(m--){
        //cout<<" ans = ";
        long long x,y;
        cin >> x >> y;
        x--;
        long long ans =0;
        if(a[x] != 0)
            s.erase({c[x], x});
        bool ok =true;
        if(y>a[x]){
            ans+= a[x]*c[x];
            y-=a[x];
            a[x] = 0;
            while(y&&!s.empty()){
                auto mi = s.begin();
                long long cost = mi->first;
                int idx = mi->second;
                s.erase(mi);
                //cout<<mi->first<<" "<<mi->second<<"y = "<<y<<endl;
                if(y>a[idx]){
                    ans+= a[idx]*cost;
                    y-=a[idx];
                    a[idx] = 0;
                }else{
                    ans+= y*cost;
                    a[idx]-=y;
                    s.insert({cost, idx});
                    y = 0;
                }
            }
            if(y)ok=false;
        }else{
            a[x]-=y;
            ans+= y*c[x];
            s.insert({c[x], x});
        }
        if(!ok)cout<<"0"<<endl;
        else cout<<ans<<endl;
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}

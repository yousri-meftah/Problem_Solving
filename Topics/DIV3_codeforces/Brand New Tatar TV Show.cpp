#include <bits/stdc++.h>
using namespace std;




void solve() {
    int n ,k;
    cin>>n>>k;
    
    set<int> s;
    map<int,int> mp;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        mp[a]++;
        s.insert(a);
    }
    vector<int> v(s.begin(),s.end());
    
    int m = v.size();
    if(m==1){
        if(n%2){
            cout<<"NO"<<endl;
        }else cout<<"YES"<<endl;
        return;
    }
    int l = 0 , r =1;
    while(r<m){
        if(v[r]-v[r-1]>k){
            int sz = r-l;
            if(sz==1){
                // cout<<" value = "<<v[r-1]<<" repeated = "<<mp[v[r-1]]<<endl;
                if(mp[v[r-1]]%2==0){
                    cout<<"YES"<<endl;
                    return;
                }
            }else{
                cout<<"YES"<<endl;
                return;
            }
            l = r;
        }
        r++;
    }
    int sz = r-l;
    if(sz==1){
        if(mp[v[r-1]]%2==0){
            cout<<"YES"<<endl;
            return;
        }
    }else{
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    
    
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
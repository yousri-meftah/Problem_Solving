#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector

bool check(int mid , vector<int> &a, vector<int> &b, int n, int m){
    int last = 0;
    int pos = 0;
    bool ok = true;
    for(auto i:b){
        while(pos<n&& a[pos] < i){
            pos++;
        }
        if(pos == n) return false;
        cout<<" value = "<<i<<" pos = "<<pos<<" a = "<<a[pos]<<endl;
        if(a[pos]>mid&&ok){
            pos = last-1;
            ok = false;
        }else{
            last=pos+1;
        }
        pos++;
    }
    return true;
}

void solve() {
    int n , c,d;
    cin >> n >> c >> d;   
    vector<vector<int>> v(n,vector<int> (n));
    map<int,int> mp;
    int mi = 1e9+7;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
            mi = min(mi,v[i][j]);
            mp[v[i][j]]++;
        }
    }
    v[0][0] = mi;
    for(int i=0;i<n;i++){
        if(i!=0){
            if(!mp[v[i-1][0]+c]){
                cout << "NO" << endl;
                return;
            }
            mp[v[i-1][0]+c]--;
            v[i][0] = v[i-1][0]+c;
        }
        for(int j=1;j<n;j++){
            if(!mp[d+v[i][j-1]] ){
                cout << "NO" << endl;
                return;
            }
            mp[d+v[i][j-1]]--;
            v[i][j] = v[i][j-1]+d;
        }
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

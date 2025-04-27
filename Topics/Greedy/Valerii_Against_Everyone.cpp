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
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for(auto &i:v)cin>>i,mp[i]++;
    for(auto i:mp)if(i.second>=2){
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;   
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}

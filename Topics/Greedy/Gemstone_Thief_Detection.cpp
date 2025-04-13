#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n ;
    cin>>n;
    vector<int>v0;
    vector<long long> v(n);
    int pos = 0;
    for(auto &i:v){
        cin>>i;
        if(i==0)v0.push_back(pos);
        pos++;

    }
    if(v0.size() == 0){
        for(auto i:v)cout<<i<<" ";
        return;
    }
    vector<int> ans(n,0);
    int y = v0.size();
    for(int i=0; i<n ;i++){
        if(v[i] != 0 ){
            int pos = upper_bound(v0.begin(), v0.end(), i) - v0.begin();
            if(pos==y){
                ans[i] = i - v0[pos-1] ;
            }else if(pos==0){
                ans[i] = v0[pos] - i;
            }
            else{
                int v1 = v0[pos] - i;
                int v2 = i - v0[pos-1];
                ans[i] = min(v1, v2);
            }
        }
    }
    for(auto i:ans)cout<<i<<" ";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) { solve(); }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector


void solve() {
    int n ;
    cin >> n ;   
    vector<int> v(n);
    for(auto &i:v)cin>>i;
    deque<int> dq;
    for(auto i:v){
        if(dq.empty()){
            dq.push_back(i);
        }else{
            if(dq.front() > i){
                dq.push_front(i);
            }else dq.push_back(i);
        }
    }
    //cout<<" ans = ";
    for(auto i:dq)cout<<i<<" ";
    cout<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}

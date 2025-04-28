#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector


void solve() {
    int n ;
    cin >> n ;   
    vector<int> v(n); 
    priority_queue<pair<int,int>> ma;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> mi;
    int pos = 0;
    for(auto &i:v){
        cin>>i;
        mi.push({i,pos});
        pos++;
    }
    string ch;
    cin>>ch;
    //cout<<" ans = ";
    for(auto i:ch){
        if(i == '0'){
            auto  p = mi.top();
            mi.pop();
            ma.push({p.first,p.second});
            cout<<p.second+1<<" ";
        }else{
            auto p = ma.top();
            ma.pop();
            cout<<p.second+1<<" ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}

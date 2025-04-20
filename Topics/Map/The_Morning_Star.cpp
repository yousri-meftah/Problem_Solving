#include <bits/stdc++.h>
using namespace std;



bool f(int x,priority_queue<int> pq,int k ){
    int cnt = 0;
    for(int i = 0; i < k; i++){
        int cnt = 0;
        while(!pq.empty()&& cnt<x){
            int y = pq.top();
            pq.pop();
            y--;
            if(y>0)pq.push(y);
            cnt++;
        }
        if( cnt<x )return false;
    }
    
    return true;
}   
void solve(){
    int n = 10;
    cin >> n ;
    vector<pair<long long,long long>> v(n);
    for(auto &i:v)cin >> i.first >> i.second;
    map<long long,long long> mx,my,mr,ml;
    for(auto i:v){
        mx[i.first]++;
        my[i.second]++;
        mr[i.first-i.second]++;
        ml[i.first+i.second]++;
    }
    long long ans = 0 ; 
    for(auto i:mx){
        ans += (i.second*(i.second-1));
    }
    for(auto i:my){
        ans += (i.second*(i.second-1));
    }
    for(auto i:mr){
        ans += (i.second*(i.second-1));
    }
    for(auto i:ml){
        ans += (i.second*(i.second-1));
    }
    cout<<" ans = ";
    cout << ans << "\n";
    
    

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
}
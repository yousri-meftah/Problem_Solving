#include <bits/stdc++.h>
using namespace std;

bool f(long long x, vector<long long> &v, vector<long long> &c, long long n, long long h){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        long long y =(long long)( (x)/(long long)c[i])  ;
        y+= ((x%c[i])>=1);
        long long z = 1LL * y * v[i];  // This ensures the whole expression is in long long
        sum += z;
        if(sum >= h) return true;
    }
    return sum >= h;
}

void solve(){
    long long n,h;
    cin >>h>> n;
    vector<int> v(n),c(n);
    for(auto &x : v) cin >> x;
    for(auto &x : c) cin >> x;
    // just change this to set , its the same for this problem
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    for(int i = 0; i < n; i++){
        pq.push({0,i});
    }
    long long sum = 0;
    long long ans = 0;
    while(sum<h){
        auto [x,y] = pq.top();
        pq.pop();
        sum += v[y];
        ans = max(ans, x +1 );
        pq.push({x+c[y],y});
        //cout<<" time = "<<time<<endl;
    }
    cout<<ans<<endl;

    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
}
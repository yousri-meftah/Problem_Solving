#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >>n;
    vector<long long> v(n+2);
    map<long long,int> mp;
    long long sum =  0;
    for(auto &x : v) {cin >> x;sum+=x;mp[x]++;}
    
    int yy  = -1;
    long long xx = 0;
    for(auto i:v){
        long long u = sum - i;
        mp[i]--;
        if(u%2){mp[i]++;continue;}
        if(mp[(u/2)] ){
            yy= i;
            xx = u/2;
            break;
        }
        mp[i]++;
    }
    if(yy == -1){
        cout << "-1" << endl;
        return;
    }
    
    cout<<" ans = ";
    bool ok=true;
    bool ok2 = true;
    for(auto i:v){
        if(i==yy&&ok){
            ok=false;
            continue;
        }
        if(i==xx&&ok2){
            ok2=false;
            continue;
        }
        cout<<i<<" ";
    }
    cout <<endl;
    
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
}
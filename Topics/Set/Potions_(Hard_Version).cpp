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
    long long n;
    cin >>n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    multiset<int> s;
    long long sum = 0;
    int ans = 0;
    for(auto i:v){
        if(i>=0){
            sum+=i;
            ans++;
        }
        else{
            if(sum>=abs(i)){
                sum+=i;
                ans++;
                s.insert(i);
                
            }
            else{
                if(s.empty())continue;
                auto it = s.begin();
                if(*it<i){
                    sum+=abs(*it);
                    sum+=i;
                    s.erase(it);
                    s.insert(i);                    
                }
            }
            
        }
        //cout<<" i = "<<i<<" ans = "<<ans<<" sum = "<<sum<<endl;
    }
    //cout<<" ans = ";
    cout << ans << endl;
    
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) { solve(); }
}
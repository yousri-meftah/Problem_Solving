#include <bits/stdc++.h>
using namespace std;

int make(int x, vector<int> &v){
    int pos = 0;
    int cnt = 0;
    while(x){
        if((x % 2) == 1 ) {
            cnt++;
        }
        v[pos] = x % 2;
        x /= 2;
        pos++;
    }
    return cnt;
}

void solve(){
    int n ;
    cin>>n;
    long long ans = 0;
    long long start = n-1;
    for(int i =1;i<=n/2;i++){
        ans+= start*2;
        start-=2;
    }
    cout<<ans/2 +1<<endl;
    

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
}
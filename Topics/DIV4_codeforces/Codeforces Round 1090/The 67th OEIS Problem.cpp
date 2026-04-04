/*
    Author: Yosri Meftah ( zeal1 or zaxxx )
    Competitive Programming Template
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> first300Primes() {
    vector<int> primes;
    int num = 2;

    while (primes.size() < 300) {
        bool isPrime = true;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.push_back(num);
        }

        num++;
    }

    return primes;
}
vector<int> primes = first300Primes();
void solve() {
    int n;
    cin >> n;
    vector<long long> v(n);
    int  m = primes.size();
    long long ma = 1e16;
    int start = 0;
    int i = 0;
    long long y = 2;
    bool ok = false;
    while(i<n&&start<m){
        // cout<<" y = "<<y<<" ma = "<<ma<<endl;
        while(y<ma&&i<n){
            if(!ok)
                y*=2;
            else ok=false;
            v[i] = y;
            i++;
        }
        // cout<<" i = "<<i<<endl;
        if(i==n)break;
        
        start++;
        if(start==m)break;
        
        // ok = true;
        y=primes[start] * primes[start-1];
        v[i] = y;
        i++;
        ok=false;
        // cout<<" y = "<<y<<endl;
    }
    // cout<<" i = "<<i<<endl;
    //verify gcd 

    set<long long> ss;
    for(int i =0;i<n-1;i++){
        // cout<<gcd(v[i],v[i+1]);
        ss.insert(gcd(v[i],v[i+1]));
    }
    // cout<<" v = ";
    
    for(auto i:v){
        cout<<i<<" ";
    }
    // cout<<" ss = "<<ss.size()<<endl;
    // cout<<endl;
    cout<<endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
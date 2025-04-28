#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector

class Sieve {
    public:
        static const int N = 6000001; // better to write it as an int
        bool prime[N];
        vector<int> primes;
    
        Sieve() {
            memset(prime, 1, sizeof prime);
            prime[0] = prime[1] = 0;
    
            int limit = sqrt(N);
            for (int i = 2; i <= limit; ++i) {
                if (prime[i]) {
                    for (int j = i * i; j < N; j += i) {
                        prime[j] = 0;
                    }
                }
            }
    
            for (int i = 2; i < N; ++i) { // start from 2
                if (prime[i]) primes.push_back(i);
            }
        }
    };

Sieve s;
void solve() {
    int n ;
    cin>>n;
    vector<long long> v(n);
    for(auto &i:v)cin>>i;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int l =0,r = n-1;
    int ans = n;    
    long long sum = 0;
    int vs = 0;
    for(auto i:v){
        if(i<s.primes[vs]){
            long long diff = s.primes[vs]-i;
            if(diff>sum)break;
            else{
                sum-=diff;
            }
        }else{
            sum+=i-s.primes[vs];
        }
        ans--;
        vs++;
    }

    cout<<ans<<endl; 
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
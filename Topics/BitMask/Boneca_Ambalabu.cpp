#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n ;
    long long value;
    cin>>n;
    vector<long long> v(n);
    for(auto &i:v)cin>>i;
    long long maa = 0;
    vector<long long> bits(32,0);
    for(auto i:v){
        long long p = 1;
        long long y= i;
        long long nb = 0;
        while(p<=y){
            if(y&p) bits[nb]++;
            p*=2;
            nb++;
        }
        maa = max(maa,p/2);
    }

    vector<pair<long long,long long>> values(32);
    long long p =1;
    for(long long i=0;i<31;i++){
        values[i].second = bits[i]*p;
        values[i].first = (n-bits[i])*p;
        p*=2;
    }
    long long ma = 0 ;
    for(auto i :v){
        long long p = 1;
        long long y= i;
        long long sum = 0;
        long long pos = 0;
        while(maa>=p){
            if(y&p)sum+=values[pos].first;
            else sum+=values[pos].second;
            p*=2;
            pos++;
        }
        ma=max(sum,ma);
    }
    cout<<ma<<endl;
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
}
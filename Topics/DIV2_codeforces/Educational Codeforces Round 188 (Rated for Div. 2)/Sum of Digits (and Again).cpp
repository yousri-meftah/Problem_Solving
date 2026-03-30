/*
    Author: Yosri Meftah ( zeal1 or zaxxx )
    Competitive Programming Template
*/

#include <bits/stdc++.h>
using namespace std;


void generate(int n,string &s){
    if(n<10){
        s+=(n+'0');
        return;
    }
    s+=to_string(n);
    int sum = 0;
    while(n){
        sum+=(n%10);
        n/=10;
    }
    generate(sum,s);

}

void solve() {
    // wow what a problem !!!! lovely one
    string s;
    cin>>s;
    int n = s.size();
    if(n==1){
        cout<<s<<endl;
        return;
    }
    map<char,int>mp;
    for(auto i:s){
        mp[i]++;
    }
    for(int i = 1 ; i<=1e6 ; i++){
        string t;
        // map<char,int>temp = mp;
        generate(i,t);
        bool ok=true;
        map<char,int>mp2;
        for(auto i:t){
            if(mp[i]==0){
                ok=false;
                break;
            }
            mp2[i]++;
        }
        long long sum = 0;
        for (auto i : mp) {
            if(i.second<(mp2[i.first])){
                ok=false;
                break;
            }
            sum += 1LL * (i.first - '0') * (i.second - (mp2[i.first]));
        }
        if(ok&&sum==i){
            // cout<<" t t= "<<t<<endl;
            string res = "";
            for(auto i:mp){
                for(int j = 0 ; j<i.second - (mp2[i.first]); j++){
                    res+=(i.first);
                }
            }
            sort(res.begin(),res.end());
            reverse(res.begin(),res.end());
            res+=t;
            cout<<res<<endl;
            return;
        }
    }

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
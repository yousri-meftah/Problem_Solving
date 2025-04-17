#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , m ,k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    int l=0 , r=0 ;
    map<int,int> mp;
    for(auto i:b)mp[i]++; //elemnts of b 
    long long ans = 0;
    int nb = 0;//how many elemnt
    map<int,int> s;//cnt of a[i] in b[i]
    while(r<n){
        s[a[r]]++;
        if(s[a[r]]<=mp[a[r]]){
            nb++;
        }
        if((r-l+1)==m){
            if(nb>=k){
                ans++;
            }
            //nejbdu l 
            if(mp[a[l]]){
                s[a[l]]--;
                if(s[a[l]]<mp[a[l]]){
                    nb--;
                }
            }
            l++;
            
        }
        r++;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
}
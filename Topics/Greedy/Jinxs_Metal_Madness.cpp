#include <bits/stdc++.h>
using namespace std;

void solve(){
    string ch;
    cin>>ch;
    vector<int> h,m;
    string s1 = "heavy" , s2 = "metal";
    int n = ch.size();
    for(int i = 0;i<n;i++){
        bool ok =false;
        for(int j = 0;j<5;j++){
            if(ch[i+j] != s1[j]){
                
                ok = true;
                break;
            }
        }
        if(!ok){
            h.push_back(i);
        
        }
    }
    for(int i = 0;i<n;i++){
        bool ok =false;
        for(int j = 0;j<5;j++){
            if(ch[i+j] != s2[j]){
                
                ok = true;
                break;
            }
        }
        if(!ok){
            m.push_back(i);
            
        }
    }
    long long ans  = 0;
    int mm = m.size();
    for(auto i:h){
        int pos = upper_bound(m.begin(),m.end(),i)-m.begin();
        if(pos<mm){
            ans += mm-pos;
        }
    }
    cout<<ans<<"\n";
    
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) { solve(); }
}
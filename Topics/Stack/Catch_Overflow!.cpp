#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod  = 1e9+7;

void solve() {
    int n ;
    cin>>n;
    long long limit = 4294967295 ;    
    stack<long long> st;
    bool ok = false;
    long long x = 0;
    while(n--){
        string ch;
        cin>>ch;
        if(ch=="for"){
            int nb ;
            cin>>nb;  
            if(ok)continue;  
            if(st.empty())st.push(nb);
            else{
                long long a  = st.top();
                if(a==-1){
                    st.push(-1);
                    continue;
                }
                long long val = a*nb;
                if(val > limit)st.push(-1);
                else st.push(val);
            }
        }
        else if(ch=="end"){
            if(ok)continue;
            st.pop();
        }else{  
            if(ok)continue;
            if(st.empty()){
                if(x== limit){
                    ok = true;
                    continue;
                }
                x++;
                continue;
            }
            long long a = st.top();
            if(a == -1){
                ok = true;
                continue;
            }
            a+= x;
            if(a > limit){
                ok=true;
            }
            else{
                x  = a;
            }
        }
    }
    if(!ok){
        cout<<x<<"\n";
    }
    else {
        cout<<"OVERFLOW!!!\n";
    }

    
}

int32_t main() {
    FAST;
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
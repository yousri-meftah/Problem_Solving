#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod  = 1e9+7;


void solve() {
    int n ;
    cin>>n;
    string ch;
    vector<string> v;
    while(n--){
        cin>>ch;
        if(ch=="pwd"){
            string temp = "";
            for(auto &i:v){
                temp += "/" +i;
            }
            temp += "/";
            cout<<temp<<endl;
        }else{
            string dir;
            cin>>dir;
            int a = dir.size();
            string temp = "";
            int ab = 0;
            if(dir[0] == '/'){
                v.clear();
                ab = 1;
            }
            for(int i = ab;i<a;i++){
                if(dir[i] == '/'){
                    if(temp==".."){
                        v.pop_back();
                        temp="";
                        continue;
                    }
                    v.push_back(temp);
                    temp="";
                }
                else temp+= dir[i];
            }
            if(temp==".."){
                v.pop_back();
                continue;
            }
            v.push_back(temp);
        }
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
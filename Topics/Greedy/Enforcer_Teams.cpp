#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int sum = a+b+c+d+e+f;
    if(sum %2 != 0){
        cout<<"NO\n";
        return;
    }
    sum /= 2;
    vector<int> v(6);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;
    v[5] = f;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                int x = v[i]+v[j]+v[k];
                if(x == sum){
                    cout<<"YES\n";
                    return;
                }
            }
        }
    }
    cout<<"NO\n";
    
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) { solve(); }
}
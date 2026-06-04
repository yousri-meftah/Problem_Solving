#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n ,k ,x;
    cin>>n>>k>>x;   
    vector<long long > v(n);
    for(auto &i:v)cin>>i;
    sort(v.begin(),v.end());
    vector<long long > diff ; 
    for(int i = 0 ; i <n -1;i++){
        if(v[i+1] - v[i] > x)
            diff.push_back(v[i+1] - v[i]);
    }
    int groups = diff.size() +1 ;
    sort(diff.begin(),diff.end());
    for(auto i:diff){
        long long need = (i-1)/x;
        if(need <= k){
            groups--;
            k-=need;
        }
    }
    cout<<groups<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n  ;
    cin>>n;
    vector<int> v(n);
    map<int, int> freq;
    int mo = 0;
    for(auto &i:v){
        cin>>i;
        freq[i]++;
        mo = max(mo, freq[i]);
    }
    vector<int> vv;
    
    int ma = 0;
    for(auto i:freq)vv.push_back(i.second);
    sort(vv.begin(), vv.end());
    int nn = vv.size();
    for(int i = 1; i <=mo; i++) {
        int start = i ;
        int cnt = 0;
        int ss = 0;
        while(true){
            int pos = lower_bound(vv.begin()+ss, vv.end(), start) - vv.begin();
            if(pos == nn) break;
            cnt+=start;
            ss= pos+1;
            start*=2;
        }
        ma=max(ma, cnt);
    }
    

    cout << ma << '\n';
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) { solve(); }
}
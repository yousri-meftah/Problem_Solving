#include <bits/stdc++.h>
using namespace std;

pair<string,string> split(string s){
    string  ch = "";
    string a,b;
    for(auto i:s){
        if(i=='_'){
            a=ch;
            ch="";
        }else{
            ch+=i;
        }
    }
    return {a,ch};
}

long long clc(map<string,bool> &ms,map<string,pair<int,int>> &mp,vector<string> &get){
    long long ans = 0;
    for(auto i:ms){
        ans+= mp[i.first].second;
    }
    unordered_set<string> st;
    for(auto s:get){
        auto pp = split(s);
        if(ms[pp.first] || ms[pp.second]){
            continue;
        }
        st.insert(pp.first);
        st.insert(pp.second);
    }
    for(auto i:st){
        ans+=mp[i].first;
    }
    return ans;
}



void solve() {
    int n , m;
    cin >> n >> m;
    vector<string> vs(n);
    map<string,pair<int,int>> mp;
    for(int i =0;i<n;i++){
        string s;
        cin>>s;
        int a,b;
        cin>>a>>b;
        mp[s] = {a,b};
        vs[i] = s;
    }
    vector<string> get(m);
    for(int i =0;i<m;i++){
        string s;
        cin>>s;
        get[i] = s;
    }
    int cnt = 1<<n;
    long long mi = INT_MAX;
    for(int i=0;i<cnt;i++){
        map<string,bool> ms;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                ms[vs[j]]=true;
            }
        }        
        long long calc = clc(ms,mp,get);
        mi = min(mi,calc);  
    }
    cout<<mi<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}

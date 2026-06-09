#include <bits/stdc++.h>
using namespace std;


long long make(vector<int> v){
    long long ans = 0 ;
    for(auto i:v){
        long long y = 1;
        if(i>1)
            y = 1LL << (i - 1);
        ans+=y;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int root = 0;
    map<int,long long> mp;
    vector<vector<int>> edge(n+1);
    map<int,string> ms;
    
    for(int i=0;i<n;i++){
        string ch ;cin>>ch;
        ms[i+1]=ch;
        int parent ;cin>>parent;
        if(parent==0){
            root= i+1;
        }else{
            edge[parent].push_back(i+1);
        }
        int k ;cin>>k;
        vector<int> v;
        while(k--){
            int skill;cin>>skill;
            v.push_back(skill);
        }
        long long value = make(v);
        // cout<<" v = "<<value<<endl;
        mp[i+1] = value;
    }
    queue<int> q;
    q.push(root);
    int d = 0;
    map<int,int>md;
    while(!q.empty()){
        int a = q.size();
        // cout<<" a = "<<a<<endl;
        while(a--){
            int u = q.front();
            q.pop();
            md[u] = d;
            for(auto i:edge[u])q.push(i);
        }
        d++;
    }
    // cout<<" here ! "<<endl;
    int qr;
    cin>>qr;
    // cout<<" qr = "<<qr<<endl;
    map<int,int> answers;
    while(qr--){
        int v;cin>>v;
        if(answers.find(v)!=answers.end()){
            cout<<ms[answers[v]]<<endl;
            continue;
        }
        int ma = -1 ;
        bool ok =true;
        int dd = md[v];
        // cout<<" v = "<<v<<" my depth = "<<dd<<endl;
        int val = -1;
        for(int i =1;i<=n;i++){
            // cout<<" i = "<<i<<" d = "<<md[i]<<endl;
            if(md[i]<=dd){
                long long value = mp[v]&mp[i];
                // cout<< " value = "<<value<<endl;
                // cout<<" me = "<<ma<<endl;
                if((value)==mp[v]){
                    if(ok){
                        val = i;
                        ma = md[i];
                        ok=false;
                    }else{
                        if(md[i]<ma){
                            ma = md[i];
                            val = i;
                        }else if(md[i]==ma){
                            if(ms[val]>ms[i]){
                                val = i ;
                                ma = md[i];
                            }
                        }
                    }
                }
            }
        }
        answers[v] = val;
        // cout<<" ma = "<<val<<endl;
        cout<<ms[val]<<endl;
    }

}
// link : https://codeforces.com/gym/697201/problem/B
// the problem from odoo hackthon , 08/06/2026
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
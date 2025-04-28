#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector


void solve() {
    int n ;
    cin >> n ;   
    string ch;
    cin>>ch;
    vector<int> ans(n+1,0);
    string s = "";
    stack<string> qi;
    qi.push("");
    for(auto i:ch){
        if(i>='0'&&i<='9'){
            string t = qi.top();
            qi.pop();
            t+=i;
            qi.push(t);
        }
        else if(i=='('){
            qi.push("");
        }else{
            string u = qi.top();
            qi.pop();
            int t = stoi(u);
            string u2 = qi.top();
            int top = stoi(u2);
            //cout<<" top = "<<top<<" t = "<<t<<endl;
            ans[t] = top;
        }
    }
    for(int i =1;i<=n;i++)cout<<ans[i]<<" ";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}

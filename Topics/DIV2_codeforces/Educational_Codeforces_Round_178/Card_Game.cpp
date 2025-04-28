#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector


void solve() {
    int n ;
    cin>>n;
    string ch;
    cin>>ch;
    //cout<<" ans  = ";
    if(ch[0]==ch[n-1]){
        if(ch[0]=='A')cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
        return ;
    }
    if(n==2){
        if(ch[0]=='A')cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
        return ;
    }
    int MA = 0,MB = 0;
    for(int i=1;i<n-1;i++){
        if(ch[i]=='A')MA = i;
        else MB = i;
    }
    if(MA>MB&& ch[n-1]=='A'){
        cout<<"Alice"<<endl;
    }else if(MA>MB&& ch[n-1]=='B'&&MB!=0){
        cout<<"Bob"<<endl;
    }else if(MB>MA&& ch[n-1]=='B'){
        cout<<"Bob"<<endl;
    }else if(MB>MA&& ch[n-1]=='A'){
        cout<<"Bob"<<endl;
    }else if(MA>MB&& ch[n-1]=='B'&&MB==0){
        cout<<"Alice"<<endl;
    }
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}

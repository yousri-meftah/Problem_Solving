#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector


void solve() {
    int n,q ;
    cin >> n>>q ;   
    deque<int> dq;
    int ma = 0;
    for(int i =0;i<n;i++){
        int a ;
        cin>>a;
        dq.push_back(a);
        ma=max(ma,a);
    }
    deque<int> dq1 = dq;
    int nb = 1;
    while(true){
        int A = dq.front();
        dq.pop_front();
        int B = dq.front();
        dq.pop_front();
        nb++;
        if(A>B){
            dq.push_back(B);
            dq.push_front(A);
            if(A==ma)break;
        }else{
            dq.push_back(A);
            dq.push_front(B);
            if(B==ma)break;
        }
        
    }
    map<int,pair<int,int>> mp;
    dq.pop_front();
    int h =dq.size();
    while(q--){
        long long m ;
        cin>>m;
        //cout<<" ans = ";
        if(m>=nb){
            int p = (long long)(m-nb)%(h);
            cout<<ma<<" "<<dq[p]<<endl;
        }else{
            deque<int> dq2 = dq1;
            if(mp.find(m)!=mp.end()){
                cout<<mp[m].first<<" "<<mp[m].second<<endl;
                continue;
            }
            m--;

            while(m--){
                int A = dq2.front();
                dq2.pop_front();
                int B = dq2.front();
                dq2.pop_front();
                if(A>B){
                    dq2.push_back(B);
                    dq2.push_front(A);
                }else{
                    dq2.push_back(A);
                    dq2.push_front(B);
                }
            }
            int yy = dq2.front();
            dq2.pop_front();
            int xx = dq2.front();
            mp[m+1] = {yy,xx};
            cout<<yy<<" "<<xx<<endl;
        }


    }
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}

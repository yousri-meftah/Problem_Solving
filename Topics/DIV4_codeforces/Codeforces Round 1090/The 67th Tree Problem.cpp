/*
    Author: Yosri Meftah ( zeal1 or zaxxx )
    Competitive Programming Template
*/

#include <bits/stdc++.h>
using namespace std;




void solve() {
    int x, y;
    cin>>x>>y;
    int n = x +y;
    if(x==1&&y==1){
        cout<<"YES"<<endl;
        cout<<"1 2"<<endl;
        return;
    }
    if( x > y  || (x==0 && n%2==0  ) || (n%2 && y==0)  ){
        cout<<"NO"<<endl;
        return ;
    } 
    if(n%2)y--;
    else x--;
    int diff = y-x;
    if(x>y){
        cout<<"NO"<<endl;
        return ;
    }
    // cout<<" x = "<<x<<" y = "<<y<<endl;
    n--;
    vector<pair<int,int>> ans;
    int start = 2;
    while(diff){
        ans.push_back({1,start++});
        y--;
        diff--;
        n--;
    }
    // cout<<" n = "<<n<<endl;
    if(!n){
        cout<<"YES"<<endl;
        for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;
        return;
    }
    ans.push_back({1,start++});
    x--;
    int save = start- 1 ;
    while(x>0){
        int yy = start;
        start++;
        ans.push_back({save , yy });
        ans.push_back({yy , start++  });
        y--;
        x--;
        n-=2;
    }
    // cout<<" y = "<<y<<" n = "<<n<<endl;
    // cout<<" size = "<<ans.size()<<endl;
    if(y){
        ans.push_back({save, start});
    }
    
    cout<<"YES"<<endl;
    // cout<<" size = "<<ans.size()<<endl;
    for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;

    // 5 , 10
    // 5 , 9
    //                  1 
    // 2 , 3 , 4  ,15     |        5               (5,5) 
    //                    |  6    8     10   12     14
    //                     | 7     9    11    13    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}